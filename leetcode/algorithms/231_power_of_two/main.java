class PowerOfTwo {
    public boolean isPowerOfTwo(int n) {
        int m = 0;

        while (Math.pow(2, m) <= n) {
            if (Math.pow(2, m) == n) {
                return true;
            }
            m++;
        }

        return false;
    }


    // Best Solution
    public boolean bestSolution(int n) {
        return n > 0 && Integer.bitCount(n) == 1;
    }
}