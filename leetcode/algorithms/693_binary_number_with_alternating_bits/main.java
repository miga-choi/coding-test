class BinaryNumberWithAlternatingBits {
    public boolean hasAlternatingBits(int n) {
        int prev = -1;

        while (n > 0) {
            if (n % 2 == prev) {
                return false;
            }
            prev = n % 2;
            n >>= 1;
        }

        return true;
    }


    // Solution
    public boolean Solution(int n) {
        /*
         * n             1 0 1 0 1 0 1 0
         * n >> 1        0 1 0 1 0 1 0 1
         * n ^ n>>1      1 1 1 1 1 1 1 1
         * n             1 1 1 1 1 1 1 1
         * n + 1       1 0 0 0 0 0 0 0 0
         * n & (n+1)     0 0 0 0 0 0 0 0
         */
        n = n ^ (n >> 1);
        return (n & n + 1) == 0;
    }
}
