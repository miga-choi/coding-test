import java.util.Arrays;

class NumberOfSegmentsInAString {
    /**
     * Built-in Function
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int countSegments(String s) {
        return Arrays.stream(s.split(" ")).filter(v -> !v.equals("")).toArray().length;
    }


    // Solution
    /**
     * Solution 1
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution1(String s) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != ' ' && (i == 0 || s.charAt(i - 1) == ' ')) {
                count++;
            }
        }

        return count;
    }

    /**
     * Solution 2
     *
     * Status flag
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution2(String s) {
        int count = 0;
        boolean inSegment = false;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                inSegment = false;
            } else if (!inSegment) {
                inSegment = true;
                count++;
            }
        }

        return count;
    }

    /**
     * Solution 3
     *
     * Built-in Function + RegEx
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution3(String s) {
        s = s.trim();
        return s.isEmpty() ? 0 : s.split("\\s+").length;
    }
}
