/* ============
    main file
   ============ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Image.h"

int main(int argc, char *argv[])
{
    // Create an image 
    Image image;
    image.header.ASCII      = "P6";
    image.header.separator  = '\n';
    image.header.width      = 10;
    image.header.separator2 = '\n';
    image.header.height     = 10;
    image.header.separator3 = '\n';
    image.header.max_color  = 255;
    image.header.separator4 = '\n';

    // Allocate memory for the image
    image.data = (unsigned char ***)malloc(image.header.width * sizeof(unsigned char ***));

    // Allocate memory for each row
    for (int i = 0; i < image.header.width; i++)
    {
        image.data[i] = (unsigned char **)malloc(image.header.height * sizeof(unsigned char**));
    }

    // Allocate memory for each pixel
    for (int i = 0; i < image.header.width; i++)
    {
        for (int j = 0; j < image.header.height; j++)
        {
            image.data[i][j] = (unsigned char *)malloc(3 * sizeof(unsigned char));
        }
    }

    // Fill the image with random values
    for (int i = 0; i < image.header.width; i++)
    {
        for (int j = 0; j < image.header.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image.data[i][j][k] = 50;
            }
        }
    }
    // Write the image to a file
    FILE *file = fopen("imgs/first_image.ppm", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "%s", image.header.ASCII);
    fprintf(file, "%c", image.header.separator);
    fprintf(file, "%d", image.header.width);
    fprintf(file, "%c", image.header.separator2);
    fprintf(file, "%d", image.header.height);
    fprintf(file, "%c", image.header.separator3);
    fprintf(file, "%d", image.header.max_color);
    fprintf(file, "%c", image.header.separator4);
    for (int i = 0; i < image.header.width; i++)
    {
        for (int j = 0; j < image.header.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                fputc(image.data[i][j][k], file);
            }
        }
    }
    fclose(file);

    // Free the memory
    for (int i = 0; i < image.header.width; i++)
    {
        for (int j = 0; j < image.header.height; j++)
        {
            free(image.data[i][j]);
        }
        free(image.data[i]);
    }
    free(image.data);

    system("convert imgs/first_image.ppm imgs/first_image.jpg");
    return 0;
}