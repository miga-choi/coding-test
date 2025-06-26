import java.util.stream.IntStream;

class PrimeNumberOfSetBitsInBinaryRepresentation {
    private boolean isPrime(int n) {
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

    public int countPrimeSetBits(int left, int right) {
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
    // Solution 1
    public int solution1(int left, int right) {
        int count = 0;
        while (left <= right) {
            count += 665772 >> Integer.bitCount(left++) & 1;
        }
        return count;
    }

    // Solution 2: Stream
    public int solution2(int left, int right) {
        return IntStream.range(left, right + 1).map(i -> 665772 >> Integer.bitCount(i) & 1).sum();
    }
}
