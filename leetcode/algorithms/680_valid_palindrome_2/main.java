class ValidPalindromeII {
    public boolean validPalindrome(String s) {
        for (int left = 0, right = s.length() - 1; left < right; left++, right--) {
            if (s.charAt(left) != s.charAt(right)) {
                int left1 = left + 1, right1 = right;
                int left2 = left, right2 = right - 1;
                while (s.charAt(left1) == s.charAt(right1) && left1 < right1) {
                    left1++;
                    right1--;
                }
                while (s.charAt(left2) == s.charAt(right2) && left2 < right2) {
                    left2++;
                    right2--;
                }
                return left1 >= right1 || left2 >= right2;
            }
        }
        return true;
    }


    // Solution
    public boolean solution(String s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }

        return true;
    }

    /* Check is s[i...j] is palindrome. */
    private boolean isPalindrome(String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
}
