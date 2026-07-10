#include <stdio.h>
#include <math.h>

double Com(double x){
    return exp(x) + 3 * x;
}

double Real(double x){
    return exp(x) + 3;
}

double error(double real, double com){
    return (fabs(real - com)) / real;
}

double Forward(double x, double h){
    return (Com(x + h) - Com(x)) / h;
}

double Backward(double x, double h){
    return (Com(x) - Com(x - h)) / h;
}

double Central(double x, double h){
    return (Com(x + h) - Com(x - h)) / (2 * h);
}

int main()
{
    double x = 4.0; 
    double h = 0.25; 

    double real_val = Real(x);

    double forward = Forward(x, h);
    double backward = Backward(x, h);
    double central = Central(x, h);

    printf("Real Value (e^%.1f + 3): %.6f\n\n", x, real_val);

    printf("Forward Difference: %.6f\n", forward);
    printf("Error: %f\n\n", error(real_val, forward));

    printf("Backward Difference: %.6f\n", backward);
    printf("Error: %f\n\n", error(real_val, backward));
    
    printf("Central Difference: %.6f\n", central);
    printf("Error: %f\n", error(real_val, central));
}