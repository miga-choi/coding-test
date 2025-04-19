#include <string>
using namespace std;

class ValidPalindromeII {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1, deleted = 0;

        while (left < right) {
            if (s.at(left) == s.at(right)) {
                left++;
                right--;
            } else {
                if (!deleted) {
                    if (s.at(left + 1) == s.at(right)) {
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
            left = 0, right = s.size() - 1, deleted = 0;
        }

        while (left < right) {
            if (s.at(left) == s.at(right)) {
                left++;
                right--;
            } else {
                if (!deleted) {
                    if (s.at(left) == s.at(right - 1)) {
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
    bool solution(string s) {
        for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
            if (s.at(left) != s.at(right)) {
                int left1 = left + 1, right1 = right;
                int left2 = left, right2 = right - 1;
                while (left1 < right1 && s.at(left1) == s.at(right1)) {
                    left1++;
                    right1--;
                }
                while (left2 < right2 && s.at(left2) == s.at(right2)) {
                    left2++;
                    right2--;
                }
                return left1 >= right1 || left2 >= right2;
            }
        }
        return true;
    }
};
