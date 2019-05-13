//
// Created by nichil on 13.05.2019.
//

#include <stdio.h>
#include <math.h>

#define EPSILON 0.05

// Function Prototypes
float f(float x);
double bisection(float x1, float x2, float epsilon);

// Implementation
float f(float x) {
    return x*x-4;
}

double bisection(float x1, float x2, float epsilon){
    float xneu = 0;
    while (fabs(x2-x1) > epsilon) {
        xneu = (x1 + x2) / 2;
        if(f(xneu) == 0){ // wenn zufällig exakt die Nullstelle getroffen wird.
            return xneu;
        }
        if (f(x1) * f(xneu) < 0){
            x2 = xneu;
        } else {
            x1 = xneu;
        }
    }
    return xneu;
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