/* ========================== 
           Image file         
   ========================== */

#ifndef __IMAGE__
#define __IMAGE__

/**
 * @brief Extra parameters of the image 
 * @param xMin The minimum x value of the image
 * @param xMax The maximum x value of the image
 * @param yMin The minimum y value of the image
 * @param yMax The maximum y value of the image
 * @param scale The scale of the image
 * @param pixWidth The width of a pixel
 * @param pixHeight The height of a pixel
 * @param convergence The array of convergence values
 */
typedef struct Parameters
{
    float xMin;
    float xMax;
    float yMin;
    float yMax;
    float scale;
    float pixWidth;
    float pixHeight;
    int  *convergence;
    unsigned convergenceSize;
} Parameters;

/**
 * @brief Pixel structure
 * @param r Red value
 * @param g Green value
 * @param b Blue value
 */
typedef struct Pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

/**
 * @brief Image header struct.
 * @ width Image width.
 * @param height Image height.
 */
typedef struct Header
{
    char *ASCII;
    char separator;
    unsigned width;
    char separator2;
    unsigned height;
    char separator3;
    unsigned char max_color;
    char separator4;
} Header;

/**
 * @brief Image struct.
 * @param header Image header.
 * @param data Image data.
 */
typedef struct Image
{
    Header header;
    Parameters parameters;
    Pixel **data;
} Image;

#endif