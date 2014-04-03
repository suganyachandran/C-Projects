/*
 * Implement Monte Carlo method for computing PI
 * Note: we use the simple random() generator of 
 * the C library. See man -s 3 random
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define OK  0

/*
 * Generate double random number 0.0 <= r <= 1.0
 *
 */
double getRandom() {
    return rand() /(double) RAND_MAX;
}

int main(void) {
     const double referencePI = 3.14159265358979;
    //const double referencePI = 3.14159;
    const double epsilon = 0.0000000001;

    int countInUnitCircle=0;
    int countAll = 0;

    double approximatedPI = 0;

    /* Initialize random number generator
     * Seed with current time
     */
    srand ( time(NULL) );

    do {
        double x,y;
        x = getRandom();
        y = getRandom();
        if ( x*x + y*y <= 1) {
            countInUnitCircle ++;
        }
        countAll ++;

        approximatedPI = 4 * countInUnitCircle /(double) countAll;

    } while ( fabs(referencePI - approximatedPI ) >= epsilon);

    /* Print results */
    printf("Points generated %d, hits in unit circle %d\n",
            countAll, countInUnitCircle);
    printf("PI reference value: %15.13f\n", referencePI);
    printf("PI   approximation: %15.13f\n", approximatedPI);
    printf("Difference = %15.13f\n", fabs(referencePI - approximatedPI ));
    return OK;
}

