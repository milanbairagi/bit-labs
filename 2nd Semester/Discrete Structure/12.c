#include <stdio.h>

int mod_exp(int a, int n, int m) {
    if (n == 0)
        return 1;
    else
        return (a * mod_exp(a, n-1, m)) % m;
}

int main() {
    int a = 2, n = 3, m = 5;
    int b = 3;

    int resultA = mod_exp(a, n, m);
    int resultB = mod_exp(b, n, m);

    printf("%d^%d %% %d = %d\n", a, n, m, resultA);
    printf("%d^%d %% %d = %d\n", b, n, m, resultB);

    printf("\nProgrammed by Milan Bairagi");
    return 0;
}
