/**
 * Two pointers
 * 
 * Complexities:
 *   N - `sSize`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(1)
 */
void reverseString(char *s, int sSize) {
    for (int i = 0; i < sSize / 2; i++) {
        char temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
}


// Solution
/**
 * Solution 1
 * 
 * Two pointers
 * 
 * Complexities:
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(1)
 */
void solution(char *s, int sSize) {
    for (int left = 0, right = sSize - 1; left < right; left++, right--) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
    }
}

/**
 * Solution 2
 * 
 * Recursion
 * 
 * Complexities:
 *   N - `sSize`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(N)
 */
static void helper(char* s, int left, int right) {
    if (left >= right) {
        return;
    }

    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;

    helper(s, left + 1, right - 1);
}

void solution2(char* s, int sSize) {
    helper(s, 0, sSize - 1);
}
