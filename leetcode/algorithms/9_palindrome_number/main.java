class PalindromeNumber {
    public boolean isPalindrome(int x) {
        String[] xArray = String.valueOf(x).split("");
        for (int i = 0; i < xArray.length / 2; i++) {
            if (!xArray[i].equals(xArray[xArray.length - i - 1])) {
                return false;
            }
        }
        return true;
    }


    // Solution
    // Solution 1: Reversing the Entire Number
    public boolean solution1(int x) {
        if (x < 0) {
            return false;
        }

        long reversed = 0;
        long temp = x;

        while (temp != 0) {
            int digit = (int) (temp % 10);
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }

    // Solution 2: Reversing Half of the Number
    public boolean solution2(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int reversed = 0;

        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return (x == reversed) || (x == reversed / 10);
    }
}
