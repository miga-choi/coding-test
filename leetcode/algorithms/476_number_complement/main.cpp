class NumberComplement {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num) {
            mask <<= 1;
        }
        return ~mask ^ num;
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
        long powerof2s = 2, temp = num;

        while (temp >> 1) {
            temp >>= 1;
            powerof2s <<= 1;
        }

        return powerof2s - num - 1;
    }

    // Best Solution 3
    int bestSolution3(int num) {
        long i;
        for (i = 1; i <= num; i *= 2) {
            num ^= i;
        }
        return num;
    }
};
