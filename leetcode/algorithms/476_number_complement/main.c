int findComplement(int num) {
    int startsWithZeroCount = 0;
    int zeroCountDone = 0;

    int reverseNum = 0;
    while (num > 0) {
        if (!zeroCountDone) {
            if (num & 1) {
                startsWithZeroCount++;
            } else {
                zeroCountDone = 1;
            }
        }

        reverseNum = (reverseNum << 1) | (num & 1 ^ 1);
        num >>= 1;
    }

    int result = 0;
    while (reverseNum > 0) {
        result = (result << 1) | (reverseNum & 1);
        reverseNum >>= 1;
    }

    return result << startsWithZeroCount;
}

// Best Solution 1
int bestSolution1(int num) {
    unsigned int mask = ~0;
    while (num & mask) {
        mask <<= 1;
    }
    return ~mask & ~num;
}

// Best Solution 2
int bestSolution2(int num) {
    long i;
    for (i = 1; i <= num; i *= 2) {
        num ^= i;
    }
    return num;
}
