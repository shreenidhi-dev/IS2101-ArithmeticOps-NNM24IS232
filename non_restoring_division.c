#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void showBin(int x, int w) {
    unsigned int m = 1u << (w - 1);
    for (int i = 0; i < w; i++) {
        printf("%d", (x & m) ? 1 : 0);
        m >>= 1;
    }
}

void nonRestDiv(int a, int b, int n) {
    int r = 0;     // remainder (A)
    int q = a;     // quotient (Q)
    int d = b;     // divisor (M)

    for (int i = 0; i < n; i++) {
        // Left shift (r,q)
        r = (r << 1) | ((q >> (n - 1)) & 1);
        q = (q << 1) & ((1 << n) - 1);

        printf("Step %d:\n", i + 1);
        printf("Before: R = "); showBin(r, n + 1);
        printf(", Q = "); showBin(q, n); printf("\n");

        if (r >= 0) {
            r = r - d;           // subtract divisor
        } else {
            r = r + d;           // add divisor
        }

        if (r >= 0) {
            q = q | 1;           // set Q0 = 1 if remainder >= 0
        }

        printf("After : R = "); showBin(r, n + 1);
        printf(", Q = "); showBin(q, n); printf("\n\n");
    }

    // Final correction if remainder < 0
    if (r < 0) r = r + d;

    printf("Final Quotient  = "); showBin(q, n); printf(" (%d)\n", q);
    printf("Final Remainder = "); showBin(r, n + 1); printf(" (%d)\n", r);
}

int main() {
    int a, b, n;
    printf("Enter Dividend: ");
    scanf("%d", &a);
    printf("Enter Divisor: ");
    scanf("%d", &b);

    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 1;
    }

    // Automatically calculate number of bits if user wants
    n = (int)floor(log2(abs(a))) + 1;

    printf("Using %d bits for quotient.\n\n", n);
    nonRestDiv(a, b, n);

    return 0;
}
