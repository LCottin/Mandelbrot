/* ========================== 
           Tools file         
   ========================== */

#ifndef __TOOLS__
#define __TOOLS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Image.h"

/**
 * @brief This function indicates if the Mandlebrot suite converges to a point
 * @param x The x coordinate of the point
 * @param y The y coordinate of the point
 * @returns max_iterations The maximum number of iterations before divergence, 0 for convergence
 */
extern int converges(const float x, const float y);

/**
 * @brief This function creates a Mandlebrot image
 * @param width The width of the image
 * @param height The height of the image
 * @param pixel_top_left_x The top left pixel of the image
 * @param pixel_top_left_y The top left pixel of the image
 * @param scale_x The scale of the image in the x axis
 * @returns image The image
 */
extern Image create_mandlebrot_image(const int width, const int height, const float pixel_top_left_x, const float pixel_top_left_y, const float scale_x);

/**
 * @brief This function writes an image to a file and frees the memory
 * @param image The image to write
 * @param filename The name of the file
 * @returns 0 if the file was written successfully, 1 otherwise
 */
extern int write_image(Image *image, const char *filename, const char *new_filename);

/**
 * @brief This function creates a new pixel based on a convergence value
 * @param value The convergence value
 * @returns pixel The new pixel
 */
extern Pixel create_pixel(const int value);

#endif