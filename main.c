#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// #include <conio.h> - not supported by the compiler in my system

int main() {
    int decimal = 0, binary = 0, choice, rem, temp_number, i, number;
    while (1) {
        // clrscr(); - not supported by the compiler in my system
        printf("\n\t\t\tBinary To Decimal And Decimal To Binary");
        printf("\n\t\t\t---------------------------------------");
        printf("\n1) Binary to decimal");
        printf("\n2) Decimal to binary");
        printf("\n3) Exit");

        printf("\nEnter your Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                i = 0;
                printf("\nEnter the binary number : ");
                scanf("%d", &binary);
                number = binary;
                while (number != 0) {
                    rem = number % 10;
                    number = number / 10;
                    if (!(rem == 1 || rem == 0)) {
                        printf("\nInvalid data");
                        goto z;
                    }
                }
                rem = 0;
                temp_number = binary;
                while (temp_number != 0) {
                    rem = temp_number % 10;
                    temp_number /= 10;
                    decimal += rem * pow(2, i);
                    i++;
                }
                printf("\nThe Binary number is \"%d\"\nThe  Decimal number is \"%d\"\n", binary, decimal);
                break;
            }

            case 2: {
                i = 1;
                printf("\nEnter the decimal number : ");
                scanf("%d", &decimal);
                rem = 0;
                temp_number = decimal;
                while (temp_number != 0) {
                    rem = temp_number % 2;
                    temp_number /= 2;
                    binary += rem * i;
                    i *= 10;
                }
                printf("\nThe Decimal number is \"%d\"\nThe Binary  number is \"%d\"\n", decimal, binary);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("\nEnter the proper choice");
            }
        }
    z:
        decimal = binary = temp_number = 0;

        // getch(); - not supported by the compiler in my system
    }

    return 0;
}
