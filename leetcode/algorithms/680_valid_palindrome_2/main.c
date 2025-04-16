#include <stdbool.h>
#include <string.h>

bool validPalindrome(char* s) {
    int left = 0, right = strlen(s) - 1, deleted = 0;

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            if (!deleted) {
                if (s[left + 1] == s[right]) {
                    left++;
                    deleted = 1;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    if (left >= right) {
        return true;
    } else {
        left = 0, right = strlen(s) - 1, deleted = 0;
    }

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            if (!deleted) {
                if (s[left] == s[right - 1]) {
                    right--;
                    deleted = 1;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }

    if (left >= right) {
        return true;
    }

    return false;
}

// Solution
bool solution(char* s) {
    for (int left = 0, right = strlen(s) - 1; left < right; left++, right--) {
        if (s[left] != s[right]) {
            int left1 = left, right1 = right - 1;
            int left2 = left + 1, right2 = right;
            while (left1 < right1 && s[left1] == s[right1]) {
                left1++;
                right1--;
            };
            while (left2 < right2 && s[left2] == s[right2]) {
                left2++;
                right2--;
            };
            return left1 >= right1 || left2 >= right2;
        }
    }
    return true;
}
