#define _CRT_SECURE_NO_WARNINGS
#include <cstdarg>
#include <cstring>
#include "Math.h"


int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a, double b) {
    return (int)(a + b);
}

int Math::Add(double a, double b, double c) {
    return (int)(a + b + c);
}

int Math::Mul(int a, int b) {
    return a * b;
}

int Math :: Mul(int a, int b, int c) {
    return a * b * c;
};

int Math :: Mul(double a, double b) {
    return (int)(a * b);
};

int Math :: Mul(double a, double b, double c) {
    return (int)(a * b * c);
};

int Math :: Add(int count, ...) {
    va_list vec;
    va_start(vec, count);
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += va_arg(vec, int);

    return sum;
};

char* Math::Add(const char* a, const char* b) {
    int l1, l2;
    l1 = strlen(a);
    l2 = strlen(b);

    char* c = new char[l1+l2+1];
    strcpy(c, a);
    strcat(c, b);
    
    return c;
}
