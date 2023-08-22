class PowerOfThree {
    public boolean isPowerOfThree(int n) {
        if (Math.log10(n) / Math.log10(3) % 1 == 0) {
            return true;
        }
        return false;
    }


    // Best Solution
    // Naive Approch using loops
    public boolean bestSolution1(int n) {
        if (n == 0)
            return false;
        while (n != 1) {
            int r = n % 3; // r: remainder
            n = n / 3;
            if (r != 0)
                return false;
        }
        return true;
    }

    public boolean bestSolution2(int n) {

        while (n >= 3) {
            if (n % 3 != 0)
                return false;
            n /= 3;
        }
        return n == 1;
    }

    // Mathematics
    public boolean bestSolution3(int n) {
        return (Math.log10(n) / Math.log10(3)) % 1 == 0;
    }
}