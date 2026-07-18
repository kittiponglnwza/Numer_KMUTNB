#include <stdio.h>

double f(double x) {
    return 43.0 * x - 180.0;
}

int main() {
    double x = 0.0;
    
    do {
        if (f(x) * f(x + 1.0) <= 0.0){
            printf("Range: [%.0f, %.0f]\n", x, x + 1.0); 
            break; 
        }
        x += 1.0;
    } while (x <= 10.0);
    
    double limit = x + 1.0;
    do {
        if (f(x) * f(x + 0.000001) <= 0.0) {
            printf("Root: %.6f\n", x);
            break;
        }
        x += 0.000001;
    } while (x <= limit);

    return 0;
}
