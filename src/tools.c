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
        const float r_n1 = r_n * r_n - i_n * i_n + x;
        const float i_n1 = 2 * r_n * i_n + y;
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

Image create_mandlebrot_image(const int width, const int height, const float pixel_top_left_x, const float pixel_top_left_y, const float scale_x)
{
    // Initialize the image
    const float scale_y = - scale_x * height / width;
    const float pixel_width = scale_x * 3.0;
    const float pixel_height = scale_y * 3.0;

    // Create an image
    Image image;
    image.header.ASCII = "P6";
    image.header.separator = ' ';
    image.header.width = width;
    image.header.separator2 = ' ';
    image.header.height = height;
    image.header.separator3 = ' ';
    image.header.max_color = 255;
    image.header.separator4 = ' ';

    // Allocate memory for the image
    image.data = (Pixel **)malloc(image.header.width * sizeof(Pixel **));
    for (size_t i = 0; i < image.header.width; i++)
    {
        image.data[i] = (Pixel *)malloc(image.header.height * sizeof(Pixel *));        
    }

    // Iterate over the image
    for (int i = 0; i < image.header.width; i++)
    {
        for (int j = 0; j < image.header.height; j++)
        {
            // Compute the x and y coordinates of the pixel
            float x = pixel_top_left_x + pixel_width * i / (image.header.width - 1);
            float y = pixel_top_left_y + pixel_height * j / (image.header.height - 1);

            // Compute the value of the pixel
            image.data[i][j] = create_pixel(7 * converges(x, y));
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
            fputc(image->data[i][j].r, file);
            fputc(image->data[i][j].g, file);
            fputc(image->data[i][j].b, file);
        }
    }

    // Close the file 
    fclose(file);

    char command[200] = "convert "; 
    strncat(command, filename, strlen(filename));
    strncat(command, " ", strlen(" "));
    strncat(command, new_filename, strlen(new_filename));

    // Execute the command
    system(command);

    // Frees the memory
    for (int i = 0; i < image->header.width; i++)
    {
        free(image->data[i]);
    }
    free(image->data);

    return 0;
}

Pixel create_pixel(const int value)
{
    Pixel pixel;

    // Sets values
    if (value < 256)
    {
        pixel.r = value;
        pixel.g = 0;
        pixel.b = 0;
    }
    else if (value < 510)
    {
        pixel.r = 255;
        pixel.g = value - 255;
        pixel.b = 0;
    }
    else if (value < 765)
    {
        pixel.r = 765 - value;
        pixel.g = 255;
        pixel.b = 0;
    }
    else if (value < 1020)
    {
        pixel.r = 0;
        pixel.g = 255;
        pixel.b = 1020 - value;
    }
    else if (value < 1275)
    {
        pixel.r = 0;
        pixel.g = 1275 - value;
        pixel.b = 255;
    }
    else if (value < 1530)
    {
        pixel.r = 1530 - value;
        pixel.g = 0;
        pixel.b = 255;
    }
    else if (value < 1785)
    {
        pixel.r = 255;
        pixel.g = 0;
        pixel.b = 1785 - value;
    }
    else
    {
        printf("Error: value %d is out of range\n", value);
        pixel.r = 255;
        pixel.g = 255;
        pixel.b = 255;
    }

    return pixel;
}