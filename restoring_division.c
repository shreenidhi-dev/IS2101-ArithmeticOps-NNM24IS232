#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Print binary of a number with given width
void printBinary(int value, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
}

// Count number of bits required to represent a number
int bitLength(int value) {
    if (value == 0) return 1;
    return (int)log2(abs(value)) + 1;
}

// Restoring division algorithm
void binaryDivision(int dividend, int divisor) {
    int steps = bitLength(dividend);
    int remainder = 0;
    int quotient = abs(dividend);
    int divisorAbs = abs(divisor);

    printf("Initial State:\n");
    printf("Remainder = "); printBinary(remainder, steps);
    printf(" | Quotient = "); printBinary(quotient, steps);
    printf(" | Divisor = "); printBinary(divisorAbs, steps);
    printf("\n\n");

    for (int i = 1; i <= steps; i++) {
        // Left shift (Remainder, Quotient)
        remainder = (remainder << 1) | ((quotient >> (steps - 1)) & 1);
        quotient = (quotient << 1) & ((1 << steps) - 1);

        remainder -= divisorAbs;

        if (remainder < 0) {
            remainder += divisorAbs;
            quotient &= ~1; // Q0 = 0
            printf("Step %d: Negative -> Restore, Q0=0\n", i);
        } else {
            quotient |= 1; // Q0 = 1
            printf("Step %d: Positive -> Q0=1\n", i);
        }

        printf("Remainder = "); printBinary(remainder, steps);
        printf(" | Quotient = "); printBinary(quotient, steps);
        printf("\n\n");
    }

    if ((dividend < 0) ^ (divisor < 0)) quotient = -quotient;
    if (dividend < 0) remainder = -remainder;

    printf("Final Quotient = %d (Binary: ", quotient);
    printBinary(quotient, steps);
    printf(")\n");
    printf("Final Remainder = %d (Binary: ", remainder);
    printBinary(remainder, steps);
    printf(")\n");
}

int main() {
    int num1, num2;
    printf("Enter dividend: ");
    scanf("%d", &num1);
    printf("Enter divisor: ");
    scanf("%d", &num2);

    if (num2 == 0) {
        printf("Error: Divide by zero!\n");
        return 1;
    }

    binaryDivision(num1, num2);
    return 0;
}
