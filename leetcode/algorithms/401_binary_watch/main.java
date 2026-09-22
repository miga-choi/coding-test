import java.util.ArrayList;
import java.util.List;

class BinaryWatch {
    /**
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> result = new ArrayList<>();

        // Hour
        for (int h = 0; h < 12; h++) {
            // Minute
            for (int m = 0; m < 60; m++) {
                if (Integer.bitCount(h) + Integer.bitCount(m) == turnedOn) {
                    result.add(String.format("%d:%02d", h, m));
                }
            }
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
    public List<String> solution1(int turnedOn) {
        List<String> result = new ArrayList<>();

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (Integer.bitCount(h) + Integer.bitCount(m) == turnedOn) {
                    result.add(h + ":" + (m < 10 ? "0" : "") + m);
                }
            }
        }

        return result;
    }

    /**
     * Solution 2
     * 
     * 10-Bitmask
     * 
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public List<String> solution2(int turnedOn) {
        List<String> result = new ArrayList<>();

        for (int mask = 0; mask < 1024; mask++) {
            if (Integer.bitCount(mask) != turnedOn) {
                continue;
            }

            int h = mask >> 6, m = mask & 63;

            if (h < 12 && m < 60) {
                result.add(h + ":" + (m < 10 ? "0" : "") + m);
            }
        }

        return result;
    }

    /**
     * Solution 3
     * 
     * Backtracking
     * 
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    private static final int[] VAL = { 8, 4, 2, 1, 32, 16, 8, 4, 2, 1 };
    private final List<String> result = new ArrayList<>();

    private void backtrack(int idx, int remain, int h, int m) {
        if (h > 11 || m > 59) {
            return;
        }

        if (remain == 0) {
            result.add(h + ":" + (m < 10 ? "0" : "") + m);
            return;
        }

        if (10 - idx < remain) {
            return;
        }

        for (int i = idx; i < 10; i++) {
            if (i < 4) {
                backtrack(i + 1, remain - 1, h + VAL[i], m);
            } else {
                backtrack(i + 1, remain - 1, h, m + VAL[i]);
            }
        }
    }

    public List<String> solution3(int turnedOn) {
        backtrack(0, turnedOn, 0, 0);
        return result;
    }

}
