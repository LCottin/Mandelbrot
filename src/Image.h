/* ========================== 
           Image file         
   ========================== */

#ifndef __IMAGE__
#define __IMAGE__

/**
 * @brief Image header struct.
 * @param width Image width.
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
    unsigned char ***data;
} Image;

#endif