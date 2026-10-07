#include <stdio.h>

// 2^5
int recur_exp(int num, int exp) {
    if (exp == 0) return 1;
    return num * recur_exp(num, exp - 1);
}


// sum of digits 
int sum(int num) {
    if (num <= 0) return 0;

    return num % 10 + sum(num/10);
}

// count of digits

int count(int num, int cnt) {
    if (num == 0) return cnt; 
    count(num/10, cnt + 1);
}

// reverse a number
int reverse(int num, int rev) {
    if (num == 0) return rev;
    return reverse(num/10, rev * 10 + num % 10);
}

int rev(int num) {
    int rev2 = 0;

    while (num != 0 ) {
        int rem = num % 10;
        rev2 = rev2*10 + rem;
        num /= 10;
    }

    return rev2;
}

// fibonacci series => 2^n
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 2) + fib(n - 1);
}

int fib2(int n) {
    int arr[2002] = {0};
    if (n <= 1) return n;

}

// tower of hanoi
int toh(int n, int from, int to, int aux) {
    if (n == 1) return 1;
    int count = toh(n-1, from, aux, to);
    count += toh(1, from, to, aux);
    count += toh(n-1, aux, to, from);
    return count;
}

int main() {
    printf("%d ", fib(4));
}