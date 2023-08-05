class AddDigits {
    public int addDigits(int num) {
        String numString = String.valueOf(num);
        while (numString.length() > 1) {
            num = 0;
            for (int i = 0; i < numString.length(); i++) {
                num += Integer.parseInt(String.valueOf(numString.charAt(i)));
            }
            numString = String.valueOf(num);
        }
        return num;
    }


    // Best Solution
    public int bestSolution(int num) {
        if (num == 0) {
            return 0;
        } else if (num % 9 == 0) {
            return 9;
        } else {
            return num % 9;
        }
    }
}