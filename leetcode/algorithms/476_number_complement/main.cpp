class NumberComplement {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num) {
            mask <<= 1;
        }
        return ~mask ^ num;
    }


    // Solution
    // Solution 1
    int solution1(int num) {
        unsigned int mask = ~0;
        while (num & mask) {
            mask <<= 1;
        }
        return ~mask & ~num;
    }

    // Solution 2
    int solution2(int num) {
        long powerof2s = 2, temp = num;
        while (temp >> 1) {
            temp >>= 1;
            powerof2s <<= 1;
        }
        return powerof2s - num - 1;
    }

    // Solution 3
    int solution3(int num) {
        long i;
        for (i = 1; i <= num; i *= 2) {
            num ^= i;
        }
        return num;
    }
};
