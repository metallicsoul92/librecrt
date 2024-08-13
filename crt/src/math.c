#include "../include/math.h"

#define EPSILON 1e-9

double sqrt(double x) {
    double guess = x / 2.0;
    double result = 0.0;
    while (fabs(guess - result) > EPSILON) {
        result = guess;
        guess = (guess + x / guess) / 2.0;
    }
    return result;
}

double fabs(double x) {
    return x < 0 ? -x : x;
}

double pow(double base, double exp) {
    if (exp == 0) return 1.0;
    double result = 1.0;
    for (int i = 0; i < fabs(exp); i++) {
        result *= base;
    }
    if (exp < 0) return 1.0 / result;
    return result;
}

/* Trigonometric functions (using Taylor series approximations) */
double sin(double x) {
    double result = x;
    double term = x;
    for (int n = 1; n < 10; n++) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        result += term;
    }
    return result;
}

double cos(double x) {
    double result = 1.0;
    double term = 1.0;
    for (int n = 1; n < 10; n++) {
        term *= -x * x / ((2 * n - 1) * (2 * n));
        result += term;
    }
    return result;
}

double tan(double x) {
    return sin(x) / cos(x);
}

double exp(double x) {
    double result = 1.0;
    double term = 1.0;
    for (int n = 1; n < 10; n++) {
        term *= x / n;
        result += term;
    }
    return result;
}

double log(double x) {
    double result = 0.0;
    double term = (x - 1) / (x + 1);
    double term_squared = term * term;
    for (int n = 1; n < 10; n += 2) {
        result += term / n;
        term *= term_squared;
    }
    return 2 * result;
}

double log10(double x) {
    return log(x) / M_LN10;
}

double ceil(double x) {
    int i = (int)x;
    return (x == (double)i) ? i : i + 1;
}

double floor(double x) {
    int i = (int)x;
    return (x == (double)i) ? i : i - 1;
}
