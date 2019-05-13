//
// Created by nichil on 13.05.2019.
//

#include <stdio.h>
#include <math.h>

#define EPSILON 0.00000000000000009

// Function Prototypes
float f(float x);
double bisection(float x1, float x2, float epsilon);

// Implementation
float f(float x) {
    return x*x-4;
}

//changed bisection implementation
double bisection(float x1, float x2, float epsilon) {
    float xneu = (x1 + x2) / 2;
    if (f(xneu) == 0) {
        return xneu;
    } else {
        if(fabs(x2-x1) > epsilon) {
            if (f(x1) * f(xneu) < 0) x2 = xneu;
            else x1 = xneu;
            //debug
            //printf("Recursive bisection call with %f,%f\n", x1, x2);
            //printf("ys are %f,%f\n", f(x1), f(x2));
            bisection(x1, x2, epsilon);
        }
    }
}

int main(int argc, const char * argv[]) {
    float x1 = 0, x2 = 0;
    printf("Geben Sie einen Wert fuer x0 ein:\n");
    scanf("%f", &x1);
    printf("Geben Sie einen Wert fuer x1 ein:\n");
    scanf("%f", &x2);
    printf("Nullstelle: %f\n", bisection(x1,x2,EPSILON)); // wir gehen davon aus, dass im
    //Intervall x0 und x1 eine Nullstelle existiert. zB zwischen 1 und 3.
    return 0;
}