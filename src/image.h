#ifndef __IMAGE__
#define __IMAGE__

/**
 * @brief Image header struct.
 * @param width Image width.
 * @param height Image height.
 */
typedef struct 
{
    const unsigned char *ASCII      = "P6";
    const unsigned char separator   = ' ';
    unsigned int width;
    const unsigned char separator2  = ' ';
    unsigned int height;
    const unsigned char separator3  = ' ';
    const unsigned char max_color   = 255;
    const unsigned char separator4  = ' ';
} Header;

/**
 * @brief Image struct
 * @param header Image header.
 * @param data Image data.
 */
typedef struct
{
    Header header;
    unsigned char *data;
} Image;

#endif