#include "tools.h"

int converges(const float x, const float y)
{
    /**
     * R(0) = x; I(0) = y; 
     * U(n+1) = U(n)^2 + R(0) + iI(0);
     *        = (R(n) + iI(n))^2 + x + iy;
     *        = R(n)^2 - I(n)^2 + 2iR(n)I(n) + x + iy;
     * 
     * R(n+1) = R(n)^2 - I(n)^2 + x;
     * I(n+1) = 2R(n)I(n) + y;
     */

    // Initialize the variables
    float r_n = x;
    float i_n = y;
    float module = r_n * r_n + i_n * i_n;
    if (module > 4)
    {
        return 0;
    }

    // Iterate until the module^2 is greater than 4 or the number of iterations is greater than 85
    for (size_t i = 1; i < 85; i++)
    {
        // Computes the next iteration
        float r_n1 = r_n * r_n - i_n * i_n + x;
        float i_n1 = 2 * r_n * i_n + y;
        module = r_n1 * r_n1 + i_n1 * i_n1;

        // Saves values
        r_n = r_n1;
        i_n = i_n1;

        // If the serie diverges, returns the number of iterations
        if (module > 4)
        {
            return i;
        }
    }

    // If the serie converges, returns 0
    return 0;
}

Image create_mandlebrot_image(const int width, const int height, const float pixel_top_left_x, const float pixel_top_left_y, const float pixel_bottom_right_x, const float pixel_bottom_right_y)
{
    // Create an image
    Image image;
    image.header.ASCII = "P6";
    image.header.separator = '\n';
    image.header.width = width;
    image.header.separator2 = '\n';
    image.header.height = height;
    image.header.separator3 = '\n';
    image.header.max_color = 255;
    image.header.separator4 = '\n';

    // Allocate memory for the image
    image.data = (unsigned char ***)malloc(image.header.width * sizeof(unsigned char ***));

    // Allocate memory for each row
    for (int i = 0; i < image.header.width; i++)
    {
        image.data[i] = (unsigned char **)malloc(image.header.height * sizeof(unsigned char**));
    }
    for (int i = 0; i < image.header.width; i++)
    {
        for (int j = 0; j < image.header.height; j++)
        {
            image.data[i][j] = (unsigned char *)malloc(3 * sizeof(unsigned char));
        }
    }

    // Iterate over the image
    for (int i = 0; i < image.header.width; i++)
    {
        for (int j = 0; j < image.header.height; j++)
        {
            // Compute the x and y coordinates of the pixel
            float x = pixel_top_left_x + (pixel_bottom_right_x - pixel_top_left_x) * i / (image.header.width - 1);
            float y = pixel_top_left_y + (pixel_bottom_right_y - pixel_top_left_y) * j / (image.header.height - 1);

            // Compute the value of the pixel
            int value = converges(x, y);
            image.data[i][j][0] = (unsigned char)(3 * value);
            image.data[i][j][1] = (unsigned char)(3 * value);
            image.data[i][j][2] = (unsigned char)(3 * value);

        }
    }

    return image;
}

int write_image(Image *image, const char *filename, const char *new_filename)
{
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Write the header
    fprintf(file, "%s", image->header.ASCII);
    fprintf(file, "%c", image->header.separator);
    fprintf(file, "%d", image->header.width);
    fprintf(file, "%c", image->header.separator2);
    fprintf(file, "%d", image->header.height);
    fprintf(file, "%c", image->header.separator3);
    fprintf(file, "%d", image->header.max_color);
    fprintf(file, "%c", image->header.separator4);

    // Write the data
    for (int i = 0; i < image->header.width; i++)
    {
        for (int j = 0; j < image->header.height; j++)
        {
            fputc(image->data[i][j][0], file);
            fputc(image->data[i][j][1], file);
            fputc(image->data[i][j][2], file);
        }
    }

    // Close the file 
    fclose(file);

    char command[150] = "convert "; 
    strncat(command, filename, strlen(filename));
    strncat(command, " ", strlen(" "));
    strncat(command, new_filename, strlen(new_filename));

    // Execute the command
    system(command);

    // Frees the memory
    for (int i = 0; i < image->header.width; i++)
    {
        for (int j = 0; j < image->header.height; j++)
        {
            free(image->data[i][j]);
        }
        free(image->data[i]);
    }
    free(image->data);

    return 0;
}