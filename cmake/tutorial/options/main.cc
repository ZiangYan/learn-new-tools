#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#ifdef USE_MYMATH
    #include "math/MathFunctions.h"
#else
    #include <math.h>
#endif

/**
 * power - Calculate the power of number.
 * @param base: Base value.
 * @param exponent: Exponent value.
 *
 * @return base raised to the power exponent.
 */
double power(double base, int exponent)
{
    int result = base;
    int i;
    
    for(i = 1; i < exponent; ++i){
        result = result * base;
    }
    return result;
}
int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    #ifdef USE_MYMATH
        double result = power(base, exponent);
        printf("Now we are using user supplied math implemention.\n");
    #else
        double result = pow(base, exponent);
        printf("Now we are using system provided math implemention.\n");
    #endif
    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}
