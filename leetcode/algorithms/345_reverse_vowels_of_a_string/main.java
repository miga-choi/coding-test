import java.util.Stack;

class ReverseVowelsOfAString {
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(N)
     */
    public String reverseVowels(String s) {
        String result = "";
        String[] sArray = s.split("");
        String vowels = "AEIOUaeiou";
        Stack<String> vowelStack = new Stack<>();

        for (String c : sArray) {
            if (vowels.contains(c)) {
                vowelStack.add(c);
            }
        }

        for (String item : sArray) {
            if (vowels.contains(item)) {
                result += vowelStack.pop();
            } else {
                result += item;
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Two Pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(N)
     */
    public String solution1(String s) {
        char[] arr = s.toCharArray();
        int left = 0, right = arr.length - 1;

        while (left < right) {
            while (left < right && !isVowel(arr[left])) {
                left++;
            }
            while (left < right && !isVowel(arr[right])) {
                right--;
            }

            if (left < right) {
                char tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        }

        return new String(arr);
    }

    private boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) >= 0;
    }

    /**
     * Solution 2
     *
     * Two Pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(N)
     */
    public String solution2(String s) {
        char[] arr = s.toCharArray();
        int left = 0, right = arr.length - 1;

        while (left < right) {
            while (left < right && !isVowel2(arr[left])) {
                left++;
            }
            while (left < right && !isVowel2(arr[right])) {
                right--;
            }

            if (left < right) {
                char tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        }

        return new String(arr);
    }

    private boolean isVowel2(char c) {
        return switch (c) {
            case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' -> true;
            default -> false;
        };
    }
}
