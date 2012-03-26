#include <iostream>
#include <time.h>

using namespace std;

long recursiveFibonacci(int n) {
    if (n < 1) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
    }
}

long nonrecursiveFibonacci(int n) {
    if (n < 1) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        double a = 1;
        double b = 1;
        for (int i = 3; i <= n; i++) {
            long tmp = b;
            b += a;
            a = tmp;
        }

        return b;
    }
}

int main() {

    int n[14] = {10, 20, 30, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    clock_t start, stop;

    for (int i = 0; i < 14; i++) {
        cout << n[i] << "\t";

        start = clock();
        cout << recursiveFibonacci(n[i]) << "\t";
        stop = clock();
        cout << stop - start << "\t";

        start = clock();
        cout << nonrecursiveFibonacci(n[i]) << "\t";
        stop = clock();
        cout << stop - start << endl;
    }

    return 0;
}
