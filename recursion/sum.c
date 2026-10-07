#include <stdio.h>


int sum_nature(int n) {
    if (n == 0) return 0;
    return n + sum_nature(n - 1);
}

int main() {
    printf("%d", sum_nature(5));
}