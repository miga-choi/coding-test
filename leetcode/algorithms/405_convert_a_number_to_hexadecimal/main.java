import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class ConvertANumberToHexadecimal {
    /**
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public String toHex(int num) {
        long longNum = num;
        List<String> hex = new ArrayList<>(
            Arrays.asList("0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f")
        );

        if (longNum == 0) {
            return hex.get(0);
        }

        if (longNum < 0) {
            longNum += Math.pow(2, 32);
        }

        String result = "";

        while (longNum > 0) {
            long remainder = longNum % 16;
            result = hex.get((int) remainder) + result;
            longNum = Math.floorDiv(longNum, 16);
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public String solution1(int num) {
        if (num == 0) {
            return "0";
        }

        char[] digits = "0123456789abcdef".toCharArray();
        StringBuilder sb = new StringBuilder();

        while (num != 0) {
            sb.append(digits[num & 15]);
            num >>>= 4;
        }

        return sb.reverse().toString();
    }

    /**
     * Solution 2
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public String solution2(int num) {
        if (num == 0) {
            return "0";
        }

        char[] digits = "0123456789abcdef".toCharArray();
        StringBuilder sb = new StringBuilder();

        for (int i = 28; i >= 0; i -= 4) {
            int nibble = (num >>> i) & 15;
            if (sb.length() > 0 || nibble != 0) {
                sb.append(digits[nibble]);
            }
        }

        return sb.toString();
    }

    /**
     * Solution 3
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public String solution3(int num) {
        if (num == 0) {
            return "0";
        }

        char[] digits = "0123456789abcdef".toCharArray();
        StringBuilder sb = new StringBuilder();

        long n = num & 0xFFFFFFFFL;
        while (n > 0) {
            sb.append(digits[(int) (n % 16)]);
            n /= 16;
        }

        return sb.reverse().toString();
    }
}