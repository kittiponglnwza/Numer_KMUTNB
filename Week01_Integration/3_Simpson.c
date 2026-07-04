#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x, 7) + 2.0 * pow(x, 3) - 1.0;
}

double F(double x) {
    return (pow(x, 8) / 8.0) + (0.5 * pow(x, 4)) - x;
}

double error(double math, double com) {
    return fabs((math - com) / math) * 100.0;
}

double simpson(double a, double b) {
    double h = (b - a) / 2.0;
    double xi = a + h;
    return (h / 3.0) * (f(a) + 4.0 * f(xi) + f(b));
}

int main() {
    double a = -1.0;
    double b = 2.0;

    double math = F(b) - F(a);
    double com = simpson(a, b);
    double err = error(math, com);

    printf("Exact : %.6f  | Simpson : %.6f  | Error (%%) : %.6f  | \n", math, com, err);

    return 0;
}