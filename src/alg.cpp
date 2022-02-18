// Copyright 2022 NNTU-CS
#include <cstdint>
#include <math.h>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (uint64_t i = 2; i <= sqrt(value); ++i) {
        if (!(value % i)) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int prime_count = 0;
    for (uint64_t value = 2; value < UINT64_MAX; ++value) {
        if (checkPrime(value)) {
            prime_count++;
        }
        if (prime_count == n) {
            return value;
        }
    }
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t m = value + 1; m < UINT64_MAX; ++m) {
        if (checkPrime(m)) {
            return m;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t a[1000], sum = 0;
    for (uint64_t i = 0; i <= hbound; ++i) {
        a[i] = i;
    }
    for (uint64_t i = 2; i * i <= hbound; ++i) {
        if (a[i] != 0) {
            for (uint64_t j = i * i; j <= hbound; j += i) {
                a[j] = 0;
            }
        }
    }
    for (int i = 2; i < hbound; i++) {
        sum += a[i];
    }
    return sum;
}
