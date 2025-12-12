#include <unordered_map>
#include <string>
using namespace std;

class RomanToInteger {
public:
    int getNumber(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return -1;
        }
    }

    /**
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int romanToInt(string s) {
        int result = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            if (getNumber(s[i]) < getNumber(s[i + 1])) {
                result -= getNumber(s[i]);
            } else {
                result += getNumber(s[i]);
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Array
     * 
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution1(string s) {
        int map[128] = {0};
        
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (map[s[i]] < map[s[i+1]]) {
                total -= map[s[i]];
            } else {
                total += map[s[i]];
            }
        }

        return total;
    }

    /**
     * Solution 2
     * 
     * Map
     * 
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    int solution2(string s) {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && m[s[i]] < m[s[i+1]]) {
                total -= m[s[i]];
            } else {
                total += m[s[i]];
            }
        }
        return total;
    }
};
