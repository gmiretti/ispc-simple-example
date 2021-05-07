#include <stdio.h>
#include "simple.h"

#ifndef N
#define N 16
#endif

int main(void) {
    float vin[N], vout[N];

    // Initialize input buffer
    for (int i = 0; i < N; ++i){
        vin[i] = (float)i;
    }

    // Call simple() function from simple.c file
    simple(vin, vout, N);

    // Print results
    for (int i = 0; i < N; ++i)
        printf("%d: simple(%f) = %f\n", i, vin[i], vout[i]);

}
