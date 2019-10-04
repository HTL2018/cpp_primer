#ifndef CP5_test7_31_h
#define CP5_test7_31_h

#include <string>
#include <stdio.h>

class Y;

class X {
    Y* y = nullptr;
};

class Y {
    X x;
};

#endif
