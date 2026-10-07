#include <stdio.h>


// factorial using recursion
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    printf("%d ", factorial(5));
    return 1;
}