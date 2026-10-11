class AddStrings {
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - The Size of `num1`
     *   M - The Size of `num2`
     *   - Time Complexity: O(max(N, M))
     *   - Space Complexity: O(1)
     */
    public String addStrings(String num1, String num2) {
        String result = "";
        int length = num1.length() > num2.length() ? num1.length() : num2.length();

        for (int i = 0; i < length; i++) {
            if (num1.length() < length) {
                num1 = "0" + num1;
            }
            if (num2.length() < length) {
                num2 = "0" + num2;
            }
        }

        int up = 0;
        for (int i = length - 1; i >= 0; i--) {
            int num = Integer.parseInt(String.valueOf(num1.charAt(i)))
                    + Integer.parseInt(String.valueOf(num2.charAt(i))) + up;
            up = 0;
            if (num > 9) {
                num -= 10;
                up += 1;
            }

            result = String.valueOf(num) + result;

            if (i == 0 && up > 0) {
                result = String.valueOf(up) + result;
            }
        }

        return result;
    }


    // Solution
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - The Size of `num1`
     *   M - The Size of `num2`
     *   - Time Complexity: O(max(N, M))
     *   - Space Complexity: O(1)
     */
    public String solution(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry != 0) {
            int a = (i >= 0) ? num1.charAt(i--) - '0' : 0;
            int b = (j >= 0) ? num2.charAt(j--) - '0' : 0;

            int sum = a + b + carry;
            sb.append((char) (sum % 10 + '0'));
            carry = sum / 10;
        }

        return sb.reverse().toString();
    }
}
