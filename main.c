// #include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void normalize(float *, int *);
void ufof(float, int);

void main() {
    // clrscr();
    float x, x1, x2;
    int   e, e1, e2, k, choice;
    printf("\n1) add");
    printf("\n2) sub");
    printf("\n3) mul");
    printf("\n4) div");
    printf("\nenter ur choice: ");
    scanf("%d", &choice);
    printf("\nenter the 1st mantissa: ");
    scanf("%f", &x1);
    printf("enter the 1nd exponent: ");
    scanf("%d", &e1);
    printf("\nenter the 2nd mantissa: ");
    scanf("%f", &x2);
    printf("enter the 2nd exponent: ");
    scanf("%d", &e2);
    switch (choice) {
        case 1: {
            k = e1 - e2;
            if (e1 > e2) {
                x2 = x2 / pow(10, k);
                e = e1;
            } else {
                x1 = x1 / pow(10, k);
                e = e2;
            }
            x = x1 + x2;
            normalize(&x, &e);
            ufof(x, e);
            break;
        }
        case 2: {
            k = e1 - e2;
            if (e1 > e2) {
                x2 = x2 / pow(10, k);
                e = e1;
            } else {
                x1 = x1 / pow(10, k);
                e = e2;
            }
            x = x1 - x2;
            normalize(&x, &e);
            ufof(x, e);
            break;
        }
        case 3: {
            x = x1 * x2;
            e = e1 + e2;
            normalize(&x, &e);
            ufof(x, e);
            break;
        }
        case 4: {
            x = x1 / x2;
            e = e1 - e2;
            normalize(&x, &e);
            ufof(x, e);
            break;
        }
        default: {
            printf("\nenter the proper choice");
            break;
        }
    }
    
    getchar();
    getchar();
}

void normalize(float *x, int *e) {

    while (*x < 0.1) {
        *x *= 10;
        *e -= 1;
    }
    while (*x >= 1.0) {
        *x /= 10;
        *e += 1;
    }
}

void ufof(float x, int e) {
    if (e > 99) {
        printf("\nThe ans is mantissa=%.4f, exponent=%d\n", x, e);
        printf("\nover flow error");
    } else if (e < -99) {
        printf("\nThe ans is mantissa =%.4f, exponent=%d\n", x, e);
        printf("\nunder flow error");
    } else {
        printf("\nThe ans is mantissa=%.4f, exponent=%d\n", x, e);
    }
}