class AddStrings {
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
    public String solution(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int carry = 0;

        for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0 || carry == 1; i--, j--) {
            int x = i < 0 ? 0 : num1.charAt(i) - '0';
            int y = j < 0 ? 0 : num2.charAt(j) - '0';
            sb.append((x + y + carry) % 10);
            carry = (x + y + carry) / 10;
        }

        return sb.reverse().toString();
    }
}