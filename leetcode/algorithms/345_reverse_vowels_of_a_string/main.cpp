#include <array>
#include <string>
using namespace std;

class ReverseVowelsOfAString {
public:
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(1)
     */
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size();

        while (i < j) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
                s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                while (1) {
                    if (s[j] == 'A' || s[j] == 'E' || s[j] == 'I' ||
                        s[j] == 'O' || s[j] == 'U' || s[j] == 'a' ||
                        s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                        s[j] == 'u') {
                        char temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                        j--;
                        break;
                    }
                    j--;
                }
            }
            i++;
        }

        return s;
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
     *   - Space Complexities: O(1)
     */
    static bool isVowel(char c) {
        switch (c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
            default:
                return false;
        }
    }

    string solution1(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                ++left;
            }
            while (left < right && !isVowel(s[right])) {
                --right;
            }

            if (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
        }

        return s;
    }

    /**
     * Solution 2
     *
     * Two Pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(1)
     */
    static constexpr auto VOWEL = [] {
        array<bool, 256> t{};
        for (char c : {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'})
            t[static_cast<unsigned char>(c)] = true;
        return t;
    }();

    string solution2(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !VOWEL[static_cast<unsigned char>(s[left])]) {
                ++left;
            }
            while (left < right && !VOWEL[static_cast<unsigned char>(s[right])]) {
                --right;
            }

            if (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
        }

        return s;
    }

    /**
     * Solution 3
     *
     * Two Pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(1)
     */
    static bool isVowel2(char c) {
        return string_view("aeiouAEIOU").find(c) != string_view::npos;
    }

    string solution3(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isVowel2(s[left])) {
                ++left;
            }
            while (left < right && !isVowel2(s[right])) {
                --right;
            }

            if (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
        }

        return s;
    }
};
