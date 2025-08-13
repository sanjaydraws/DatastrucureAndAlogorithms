/**
 * Stack height = n
 * Recursive approach to calculate x^n
 */

#include <stdio.h>

int calcPower(int x, int n) {
    if (n == 0) return 1;        // base case: x^0 = 1
    if (x == 0) return 0;        // 0^n = 0 (when n > 0)

    int xPowernm1 = calcPower(x, n - 1); // recursion step
    int xPown = x * xPowernm1;
    return xPown;
}

int main() {
    int x = 2, n = 5;
    int ans = calcPower(x, n);
    printf("ans = %d\n", ans); // 32
    return 0;
}
