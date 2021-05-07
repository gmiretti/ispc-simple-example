# ISPC Simple example

A really simple example about how to built and test your ISPC code along with your existing C code.

The idea is to show simplest (not optimal) way to test a new ISPC implementation of an existant C implementation.

You had the `run_simple` application and simple module written in C, `simple.c`. 

Then you wanted to build ISPC implementation `run_simple_ispc` using ISPC implementation, `simple.ispc`.

And after that you wanted to test them both in `test_simple`, no matter you had the tests or not.

In order to do that we just took [ISPC's simple example](https://github.com/ispc/ispc/tree/v1.15.0/examples/simple), built it with a Makefile and test it with [Unity](https://github.com/ThrowTheSwitch/Unity)
