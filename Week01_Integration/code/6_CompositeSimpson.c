#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x);
}

double F(double x) {
    return x * log(x) - x;
}

double error(double math, double com) {
    return fabs((math - com) / math) * 100.0;
}

double CompositeSimsion(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        if (i % 2 != 0) {
            sum += 4.0 * f(xi);
        } else {
            sum += 2.0 * f(xi);
        }
    }
    return (h / 3.0) * sum;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    double math = F(b) - F(a);
    int arr[] = {2, 4, 6};
    printf("  Num     |  Exact     |  Simpson   |  Error (%%)   |\n");
    for (int i = 0; i < 3; i++) {
        int n = arr[i];
        double com = CompositeSimsion(a, b, n);
        double err = error(math, com);
        printf("%d   | %.6f   | %.6f   | %.6f   | \n", n, math, com, err);
    }
    return 0;
}
