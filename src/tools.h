/* ========================== 
           Tools file         
   ========================== */

#ifndef __TOOLS__
#define __TOOLS__

#include <stdio.h>

/**
 * @brief This function indicates if the Mandlebrot suite converges to a point
 * @param x The x coordinate of the point
 * @param y The y coordinate of the point
 * @returns max_iterations The maximum number of iterations before divergence, 0 for convergence
 */
extern int converges(const float x, const float y);

#endif