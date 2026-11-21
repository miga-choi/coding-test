import java.util.ArrayList;
import java.util.List;

class KeyboardRow {
    /**
     * Row Lookup Table + First-Letter Row Check
     *
     * Complexities:
     *   i - Length of iᵗʰ Word in `words`
     *   - Time Complexity: O(Σ lenᵢ²)
     *   - Space Complexity: O(1)
     */
    public String[] findWords(String[] words) {
        List<String> result = new ArrayList<>();

        for (String word : words) {
            if (word.toLowerCase().matches("[qwertyuiop]*")
                    || word.toLowerCase().matches("[asdfghjkl]*")
                    || word.toLowerCase().matches("[zxcvbnm]*")) {
                result.add(word);
            }
        }

        return result.toArray(String[]::new);
    }


    // Solution
    /**
     * Solution 1
     *
     * Hash Lookup (Row Index Array)
     *
     * Complexities:
     *   n - The Size of `words`
     *   m - Average word length
     *   - Time Complexity: O(n * m)
     *   - Space Complexity: O(1)
     */  
    public String[] solution1(String[] words) {
        int[] row = new int[26];
        String[] rows = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };

        for (int r = 0; r < 3; r++) {
            for (char c : rows[r].toCharArray()) {
                row[c - 'a'] = r;
            }
        }

        List<String> result = new ArrayList<>();

        for (String word : words) {
            String lower = word.toLowerCase();
            int target = row[lower.charAt(0) - 'a'];

            boolean sameRow = true;
            for (int i = 1; i < lower.length(); i++) {
                if (row[lower.charAt(i) - 'a'] != target) {
                    sameRow = false;
                    break;
                }
            }

            if (sameRow) {
                result.add(word);
            }
        }

        return result.toArray(String[]::new);
    }

    /**
     * Solution 2
     *
     * Bitmask
     *
     * Complexities:
     *   n - The Size of `words`
     *   m - Average word length
     *   - Time Complexity: O(n * m)
     *   - Space Complexity: O(1)
     */
    public String[] solution2(String[] words) {
        int[] rowMask = new int[3];
        String[] rows = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };

        for (int r = 0; r < 3; r++) {
            for (char c : rows[r].toCharArray()) {
                rowMask[r] |= 1 << (c - 'a');
            }
        }

        List<String> result = new ArrayList<>();

        for (String word : words) {
            int mask = 0;

            for (char c : word.toLowerCase().toCharArray()) {
                mask |= 1 << (c - 'a');
            }

            for (int r = 0; r < 3; r++) {
                if ((mask & rowMask[r]) == mask) {
                    result.add(word);
                    break;
                }
            }
        }

        return result.toArray(String[]::new);
    }
}
