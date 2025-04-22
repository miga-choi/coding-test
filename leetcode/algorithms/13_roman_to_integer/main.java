import java.util.HashMap;
import java.util.Map;

class RomanToInteger {
    public int romanToInt(String s) {
        Map<String, Integer> romanMap = new HashMap<String, Integer>();
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
    // Solution 1
    public int solution1(String s) {
        Map<Character, Integer> m = new HashMap<>();

        m.put('I', 1);
        m.put('V', 5);
        m.put('X', 10);
        m.put('L', 50);
        m.put('C', 100);
        m.put('D', 500);
        m.put('M', 1000);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && m.get(s.charAt(i)) < m.get(s.charAt(i + 1))) {
                ans -= m.get(s.charAt(i));
            } else {
                ans += m.get(s.charAt(i));
            }
        }

        return ans;
    }

    // Solution 2
    public int solution2(String s) {
        int ans = 0, num = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            switch (s.charAt(i)) {
                case 'I':
                    num = 1;
                    break;
                case 'V':
                    num = 5;
                    break;
                case 'X':
                    num = 10;
                    break;
                case 'L':
                    num = 50;
                    break;
                case 'C':
                    num = 100;
                    break;
                case 'D':
                    num = 500;
                    break;
                case 'M':
                    num = 1000;
                    break;
            }
            if (4 * num < ans) {
                ans -= num;
            } else {
                ans += num;
            }
        }
        return ans;
    }
}
