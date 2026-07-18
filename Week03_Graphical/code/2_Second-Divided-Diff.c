#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(x / 3.0) + (x * x);
}

// f''(x) = (1/9)*e^(x/3) + 2
double f_double_prime(double x) {
    return (1.0 / 9.0) * exp(x / 3.0) + 2.0;
}

int main() {
    double x = -2.5;
    double h = 0.1;
    
    double true_val = f_double_prime(x);
    
    // 2.1 
    double forward = (-f(x + 3*h) + 4*f(x + 2*h) - 5*f(x + h) + 2*f(x)) / (h * h);
    double err_forward = fabs((true_val - forward) / true_val) * 100.0;
    
    // 2.2 
    double backward = (2*f(x) - 5*f(x - h) + 4*f(x - 2*h) - f(x - 3*h)) / (h * h);
    double err_backward = fabs((true_val - backward) / true_val) * 100.0;
    
    // 2.3 Central 
    double central = (-f(x + 2*h) + 16*f(x + h) - 30*f(x) + 16*f(x - h) - f(x - 2*h)) / (12.0 * h * h);
    double err_central = fabs((true_val - central) / true_val) * 100.0;
    
    printf("True Value of f''(-2.5) = %.8f\n\n", true_val);
    
    printf("2.1 Forward O(h^2):\n");
    printf("    Approx = %.8f\n", forward);
    printf("    Error  = %.5f%%\n\n", err_forward);
    
    printf("2.2 Backward O(h^2):\n");
    printf("    Approx = %.8f\n", backward);
    printf("    Error  = %.5f%%\n\n", err_backward);
    
    printf("2.3 Central O(h^4):\n");
    printf("    Approx = %.8f\n", central);
    printf("    Error  = %.5f%%\n\n", err_central);

    return 0;
}
