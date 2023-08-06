class UglyNumber {
    public boolean isUgly(int n) {
        if (n < 1) {
            return false;
        }

        while (n > 1) {
            if (n % 5 == 0) {
                n /= 5;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 2 == 0) {
                n /= 2;
            } else {

                return false;
            }
        }

        return true;
    }


    // Best Solution
    public boolean bestSolution(int n) {
        for (int i = 2; i < 6 && n > 0; i++) {
            while (n % i == 0) {
                n /= i;
            }
        }
        return n == 1;
    }
}