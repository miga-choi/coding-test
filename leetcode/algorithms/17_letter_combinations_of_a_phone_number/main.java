import java.util.ArrayList;
import java.util.List;
import java.util.Map;

class LetterCombinationsOfAPhoneNumber {
    /**
     * Recursion: Backtracking (DFS)
     *
     * Complexities:
     *   - Time Complexity: O(4ᴺ)
     *   - Space Complexity: O(N)
     */
    Map<Character, String> lettersMap = Map.of(
            '2', "abc",
            '3', "def",
            '4', "ghi",
            '5', "jkl",
            '6', "mno",
            '7', "pqrs",
            '8', "tuv",
            '9', "wxyz");

    private void backtracking(String digits, List<String> result, String row, int index) {
        if (index == digits.length()) {
            result.add(row);
            return;
        }

        String letters = lettersMap.get(digits.charAt(index));
        for (int i = 0; i < letters.length(); i++) {
            row += letters.charAt(i);
            backtracking(digits, result, row, index + 1);
            row = row.substring(0, row.length() - 1);
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        String row = "";

        backtracking(digits, result, row, 0);

        return result;
    }


    // Solution
    /**
     * Recursion: Backtracking (DFS)
     *
     * Complexities:
     *   - Time Complexity: O(4ᴺ)
     *   - Space Complexity: O(N)
     */
    private static final String[] KEYPAD = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    private void backtrack(List<String> result, String digits, StringBuilder current, int index) {
        if (index == digits.length()) {
            result.add(current.toString());
            return;
        }

        int digit = digits.charAt(index) - '0';
        String letters = KEYPAD[digit];

        for (char letter : letters.toCharArray()) {
            current.append(letter);
            
            backtrack(result, digits, current, index + 1);
            
            current.deleteCharAt(current.length() - 1);
        }
    }

    public List<String> solution(String digits) {
        List<String> result = new ArrayList<>();
        
        if (digits == null || digits.length() == 0) {
            return result;
        }

        backtrack(result, digits, new StringBuilder(), 0);
        
        return result;
    }
}
