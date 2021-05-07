#include <math.h>

float simple_op(float v) {
    if (v < 3.)
        v = v * v;
    else
        v = sqrt(v);
    return v;
}

void simple(float vin[], float vout[], int count){
    for (int i = 0; i < count; ++i){
        vout[i] = simple_op(vin[i]);
    }
}

