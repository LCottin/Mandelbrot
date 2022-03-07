/* ============
    main file
   ============ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Image.h"
#include "tools.h"

int main(int argc, char *argv[])
{
    /*
    // Creates a serie of files
    float start_x1 = -2;
    float start_y1 = 1;
    float start_x2 = 1;
    float start_y2 = -1;
    const int iterations = 50;

    const float goal_x = -0.99;
    const float goal_y = 0.3;
    const float step_x1 = (goal_x - start_x1) / iterations;
    const float step_y1 = (goal_y - start_y1) / iterations;
    const float step_x2 = (goal_x - start_x2) / iterations;
    const float step_y2 = (goal_y - start_y2) / iterations;

    char filename[40];
    char new_filename[40];
    
    for (int i = 0; i < iterations; i++)
    {
        // Create a Mandlebrot image
        Image mandlebrot_image = create_mandlebrot_image(900, 600, start_x1, start_y1, start_x2, start_y2);

        // Write the image to a file
        memset(filename, 0, sizeof(filename));
        memset(new_filename, 0, sizeof(new_filename));
        sprintf(filename, "imgs/PPM/mandlebrot_video%d%d.ppm", i/10, i%10);
        sprintf(new_filename, "imgs/JPG/mandlebrot_video%d%d.jpg", i/10, i%10);
        write_image(&mandlebrot_image, filename, new_filename);

        // Update the start coordinates
        start_x1 += step_x1;
        start_y1 += step_y1;
        start_x2 += step_x2;
        start_y2 += step_y2;
    }
   
    system("ffmpeg -framerate 10 -i imgs/JPG/mandlebrot_video%2d.jpg imgs/video/video.avi");
    system("rm imgs/PPM/*");
    */

    // Create a Mandlebrot image
    Image mandlebrot_image = create_mandlebrot_image(900, 600, -0.743662, 0.131810, 0.000014);
    write_image(&mandlebrot_image, "imgs/PPM/mandlebrot3.ppm", "imgs/JPG/mandlebrot3.jpg");

    return 0;
}