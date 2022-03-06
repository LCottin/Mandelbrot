/* ============
    main file
   ============ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Image.h"
#include "tools.h"

int main(int argc, char *argv[])
{
    // Create a Mandlebrot image
    Image mandlebrot_image = create_mandlebrot_image(900, 600, -2, 1, 1, -1);

    int success = write_image(&mandlebrot_image, "imgs/mandlebrot_image.ppm");

    if (success == 0)
        printf("Image written successfully!\n");
    else
        printf("Error writing image!\n");
   
    return 0;
}