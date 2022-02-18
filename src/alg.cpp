// Copyright 2022 NNTU-CS
#include <math.h>
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    for (uint64_t i = 2; i <= sqrt(value); ++i) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int prime_count = 0;
    for (uint64_t value = 2; ; ++value) {
        if (checkPrime(value)) {
            prime_count++;
        }
        if (prime_count == n) {
            return value;
        }
    }
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t m = value + 1; ; ++m) {
        if (checkPrime(m)) {
            return m;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i <= hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
