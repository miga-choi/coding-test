import java.util.HashMap;
import java.util.Map;

class RomanToInteger {
    /**
     * HashMap
     *
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int romanToInt(String s) {
        Map<String, Integer> romanMap = new HashMap<>();
        romanMap.put("I", 1);
        romanMap.put("V", 5);
        romanMap.put("X", 10);
        romanMap.put("L", 50);
        romanMap.put("C", 100);
        romanMap.put("D", 500);
        romanMap.put("M", 1000);

        s = s.replaceAll("CM", "DCCCC")
                .replaceAll("CD", "CCCC")
                .replaceAll("XC", "LXXXX")
                .replaceAll("XL", "XXXX")
                .replaceAll("IX", "VIIII")
                .replaceAll("IV", "IIII");

        int result = 0;
        for (String c : s.split("")) {
            result += romanMap.get(c);
        }

        return result;
    }


    // Solution
    private int getValue(char c) {
        return switch (c) {
            case 'I' -> 1;
            case 'V' -> 5;
            case 'X' -> 10;
            case 'L' -> 50;
            case 'C' -> 100;
            case 'D' -> 500;
            case 'M' -> 1000;
            default -> 0;
        };
    }

    /**
     * Solution 1
     * 
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution1(String s) {
        int total = 0;
        int length = s.length();
        
        for (int i = 0; i < length; i++) {
            int currentValue = getValue(s.charAt(i));
            
            if (i < length - 1 && currentValue < getValue(s.charAt(i + 1))) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
        }
        
        return total;
    }

    /**
     * Solution 2
     * 
     * Right-to-Left
     * 
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution2(String s) {
        int total = 0;
        int prevValue = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int currentValue = getValue(s.charAt(i));

            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
            
            prevValue = currentValue;
        }

        return total;
    }
}
