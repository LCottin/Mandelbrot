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