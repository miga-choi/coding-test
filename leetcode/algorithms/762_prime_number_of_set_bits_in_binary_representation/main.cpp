class PrimeNumberOfSetBitsInBinaryRepresentation {
public:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }

        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;

        for (int i = left; i <= right; i++) {
            int bits = 0;
            int n = i;

            while (n > 0) {
                bits += n % 2;
                n /= 2;
            }

            if (isPrime(bits)) {
                count++;
            }
        }

        return count;
    }


    // Solution
    int solution(int left, int right) {
        int count = 0;
        while (left <= right) {
            count += 665772 >> __builtin_popcount(left++) & 1;
        }
        return count;
    }
};
