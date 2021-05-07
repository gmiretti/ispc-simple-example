#include <stdio.h>
#include <stdlib.h>
// Include test suite
#include "unity.h"
// Include the header from the c implementation
#include "simple.h"
// Include the header file that the ispc compiler generates
#include "simple_ispc.h"

#ifndef N
#define N 16
#endif

// every test file requires this function
// setUp() is called before each test case function
void setUp(void) {
    printf("\nSetting up stuff before test\n");
}

// every test file requires this function
// tearDown() is called after each test case function
void tearDown(void) {
    printf("\nCleaning up stuff after test\n");
}

//test deterministic stuff
void test_simple(void) {
    float vin[N], vout[N], vout_ispc[N], vexpected[N];

    // Initialize input buffer and expected results
    for (int i = 0; i < N; ++i){
        vin[i] = (float)i;
        vexpected[i] = simple_op((float)i);
    }

    // Call simple() function from simple.c file
    simple(vin, vout, N);

    // Call simple_ispc() function from simple.ispc file
    simple_ispc(vin, vout_ispc, N);

    // Print results
    printf("i: expected[i], vin[i], simple(vin)[i], simple_ispc(vin)[i]\n");
    for (int i = 0; i < N; ++i)
        printf("%d: %f, %f, %f, %f\n", 
            i, vexpected[i], vin[i], vout[i], vout_ispc[i]);

    // Verify simple result
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(vexpected, vout, N);
    // Verify simple_ispc result
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(vexpected, vout_ispc, N);
}

int main(void) {
    UNITY_BEGIN();
    // We should list all tests here
    RUN_TEST(test_simple);
    return UNITY_END();
}