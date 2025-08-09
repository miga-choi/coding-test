class ZigzagConversion {
    /**
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    public String convert(String s, int numRows) {
        int sLen = s.length();

        if (numRows == 1 || numRows > sLen) {
            return s;
        }

        String result = "";
        int cycleLen = numRows * 2 - 2;
        char[] sArray = s.toCharArray();

        for (int row = 0; row < numRows; row++) {
            for (int cycle = row; cycle < sLen; cycle += cycleLen) {
                result += sArray[cycle];

                if (row > 0 && row < numRows - 1) {
                    int diag_idx = cycle + cycleLen - row * 2;
                    if (diag_idx < sLen) {
                        result += sArray[diag_idx];
                    }
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    public String solution1(String s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();
        }

        int currentRow = 0;
        boolean goingDown = false;

        for (char c : s.toCharArray()) {
            rows[currentRow].append(c);

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }

        return result.toString();
    }

    /**
     * Solution 2
     * 
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    public String solution2(String s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        StringBuilder result = new StringBuilder();
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int r = 0; r < numRows; r++) {
            for (int i = 0; i + r < n; i += cycleLen) {
                result.append(s.charAt(i + r));

                if (r != 0 && r != numRows - 1) {
                    int secondJ = i + cycleLen - r;
                    if (secondJ < n) {
                        result.append(s.charAt(secondJ));
                    }
                }
            }
        }

        return result.toString();
    }
}
