class PowerOfThree {
    public boolean isPowerOfThree(int n) {
        if (Math.log10(n) / Math.log10(3) % 1 == 0) {
            return true;
        }
        return false;
    }


    // Solution
    // Solution 1: Naive Approch using loops
    public boolean solution1(int n) {
        if (n == 0) {
            return false;
        }
        while (n != 1) {
            int r = n % 3; // r: remainder
            n = n / 3;
            if (r != 0) {
                return false;
            }
        }
        return true;
    }

    // Solution 2
    public boolean solution2(int n) {
        while (n >= 3) {
            if (n % 3 != 0)
                return false;
            n /= 3;
        }
        return n == 1;
    }

    // Solution 3: Mathematics
    public boolean solution3(int n) {
        return (Math.log10(n) / Math.log10(3)) % 1 == 0;
    }
}
