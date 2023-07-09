#include <iostream>
#include <cstdlib>
#include <cmath>

bool isWitnessComposite(int witness, int n) {
    int t = 0;
    int u = n - 1;

    while (u % 2 == 0) {
        t++;
        u /= 2;
    }

    int x_prev = static_cast<int>(std::pow(witness, u)) % n;
    int x_curr;

    for (int i = 0; i < t; i++) {
        x_curr = (x_prev * x_prev) % n;

        if (x_curr == 1 && x_prev != 1 && x_prev != n - 1) {
            return true;
        }

        x_prev = x_curr;
    }

    if (x_curr != 1) {
        return true;
    }

    return false;
}

bool isPrime(int n, int k) {
    if (n <= 1 || n == 4) {
        return false;
    }

    if (n <= 3) {
        return true;
    }

    for (int i = 0; i < k; i++) {
        int witness = 2 + std::rand() % (n - 3);

        if (isWitnessComposite(witness, n)) {
            return false;
        }
    }

    return true;
}

int main() {
    int n = 30; // Number to test for primality
    int k = 1; // Number of iterations (witnesses)

    bool isPrimeResult = isPrime(n, k);

    if (isPrimeResult) {
        std::cout << n << " is probably prime." << std::endl;
    } else {
        std::cout << n << " is composite." << std::endl;
    }

    return 0;
}
