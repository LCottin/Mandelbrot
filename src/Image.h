/* ========================== 
           Image file         
   ========================== */

#ifndef __IMAGE__
#define __IMAGE__

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
    Pixel **data;
} Image;

#endif