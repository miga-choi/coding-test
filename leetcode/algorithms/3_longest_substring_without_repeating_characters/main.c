#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int charMap[128];
    memset(charMap, -1, sizeof(charMap));

    int left = 0;
    int maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char currentChar = s[right];

        if (charMap[currentChar] > -1 && charMap[currentChar] >= left) {
            left = charMap[currentChar] + 1;
        }

        charMap[currentChar] = right;

        int length = right - left + 1;

        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}


// Solution
// Solution 1:
int solution1(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int charIndex[128];
    memset(charIndex, -1, sizeof(charIndex));
    int left = 0;

    for (int right = 0; right < n; right++) {
        if (charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1;
        }

        charIndex[s[right]] = right;

        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
        }
    }

    return maxLength;
}

// Solution 2:
int solution2(char* s) {
    // SLIDING WINDOW  - TIME COMPLEXITY O(2n)
    //                   SPACE COMPLEXITY O(m) - size of array
    int sLength = strlen(s);

    int store[256] = {0}; // array to store the occurences of all the characters
    int l = 0;            // left pointer
    int r = 0;            // right pointer
    int ans = 0;          // initializing the required length as 0

    // iterate over the string till the right pointer reaches the end of the string
    while (r < sLength) {
        // increment the count of the character present in the right pointer
        store[s[r]]++;

        // if the occurence become more than 1 means the char is repeate
        while (store[s[r]] > 1) {
            // reduce the occurence of temp as it might be present ahead also in the string
            store[s[l]]--;

            // contraction of the present window till the occurence of the 't' char becomes 1
            l++;
        }

        if (r - l + 1 > ans) {
            // As the index starts from 0 , ans will be (right pointer-left pointer + 1)
            ans = r - l + 1;
        }

        // now will increment the right pointer
        r++;
    }

    return ans;
}
