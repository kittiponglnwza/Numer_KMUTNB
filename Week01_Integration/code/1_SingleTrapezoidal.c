#include <stdio.h>
#include <math.h>

double f(double x) {
    return 4.0 * pow(x, 5) - 3.0 * pow(x, 4) + pow(x, 3) - 6.0 * x + 2.0;
}

double F(double x) {
    return ((2.0 * pow(x, 6)) / 3.0) - (3.0 * pow(x, 5) / 5.0) + (pow(x, 4) / 4.0) - (3.0 * pow(x, 2)) + 2.0 * x;
}

double error(double math, double com) {
    return fabs((math - com) / math) * 100.0;
}

double trapezoid(double a, double b) {
    double h = b - a;
    return (h / 2.0) * (f(a) + f(b));
}

int main() {
    double a = 2.0;
    double b = 8.0;

    double math = F(b) - F(a);
    double com = trapezoid(a, b);
    double err = error(math, com);

    printf("  Exact  = %.6f   |  Trapezoid  = %.6f |  Error (%%) = %.6f ", math, com, err);
    return 0;
}
