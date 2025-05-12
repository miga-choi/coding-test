class Base7 {
    public String convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        String result = "";
        boolean ifNegative = num < 0;
        if (ifNegative) {
            num *= -1;
        }

        while (num > 0) {
            int remainder = num % 7;
            num /= 7;
            result = String.valueOf(remainder) + result;
        }

        if (ifNegative) {
            result = "-" + result;
        }

        return result;
    }


    // Solution
    public String solution(int num) {
        if (num < 0) {
            return "-" + solution(-num);
        }
        if (num < 7) {
            return Integer.toString(num);
        }
        return solution(num / 7) + Integer.toString(num % 7);
    }
}
