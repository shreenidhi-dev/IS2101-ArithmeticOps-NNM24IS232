#include <stdio.h>
#include <stdlib.h>

// absolute value function
int myAbs(int x) {
    return (x < 0) ? -x : x;
}

// shift and add multiplication
void shiftAddMultiply(int num1, int num2, int bits) {
    int Acc = 0;                  // Accumulator
    int Mul = myAbs(num1);        // Multiplicand (positive)
    int Mulr = myAbs(num2);       // Multiplier (positive)
    int steps = bits;

    while (steps > 0) {
        // Check last bit of multiplier
        if (Mulr & 1) {
            Acc = Acc + Mul;
            printf("Step %d: last bit=1 → Acc = Acc + Mul = %d\n", bits - steps + 1, Acc);
        } else {
            printf("Step %d: last bit=0 → No addition, Acc = %d\n", bits - steps + 1, Acc);
        }

        // Right shift Acc and Mulr together
        Mulr = ((Acc & 1) << (bits - 1)) | (Mulr >> 1);
        Acc = Acc >> 1;

        printf("After shifting: Acc=%d, Mulr=%d\n", Acc, Mulr);
        steps--;
    }

    int result = (Acc << bits) | Mulr;   // combine Acc and Mulr

    // adjust sign
    if ((num1 < 0) ^ (num2 < 0)) {
        result = -result;
    }

    printf("\nFinal Result: %d\n", result);
}

int main() {
    int x, y;
    printf("Enter first number (multiplicand): ");
    scanf("%d", &x);
    printf("Enter second number (multiplier): ");
    scanf("%d", &y);

    shiftAddMultiply(x, y, 8); // 8-bit size
    return 0;
}