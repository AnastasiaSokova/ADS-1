// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    uint64_t i = 2, j = 0;
    while (i * i <= value && j != 1) {
        if (value % i == 0) {
            j = 1;
        } else {
            i += 1;
        }
    }
    if (j == 1) {
        return false;
    } else {
        return true;
    }
}

uint64_t nPrime(uint64_t n) {
    int k = 0;
    for (uint64_t value = 2; value < UINT64_MAX; ++value) {
        uint64_t i = 2, j = 0;
        while (i * i <= value && j != 1) {
            if (value % i == 0) {
                j = 1;
            } else {
                i += 1;
            }
        }
        if (j != 1) {
            k++;
        }
        if (k == n) {
            return value;
        }
    }
}

uint64_t nextPrime(uint64_t value) {
    for (uint64_t m = value + 1; m < UINT64_MAX; ++m) {
        uint64_t i = 2, j = 0;
        while (i * i <= m && j != 1) {
            if (m % i == 0) {
                j = 1;
            } else {
                i += 1;
            }
        }
        if (j != 1) {
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
