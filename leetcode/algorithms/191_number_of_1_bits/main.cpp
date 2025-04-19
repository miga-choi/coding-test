class NumberOf1Bits {
public:
    int hammingWeight(int n) {
        int count = 0;

        for (int i = 0; i < 32; i++) {
            if (n & 1) {
                count++;
            }
            n = n >> 1;
        }

        return count;
    }


    // Solution
    int solution(int n) {
        int count = 0;

        while (n) {
            n &= (n - 1);
            count++;
        }

        return count;
    }
};
