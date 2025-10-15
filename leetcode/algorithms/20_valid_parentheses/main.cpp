#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class ValidParentheses {
public:
    /**
     * LIFO (Last-In, First-Out): Stack
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    bool isValid(string s) {
        stack<char> char_stack;

        for (char c : s) {
            switch (c) {
                case '(':
                    char_stack.push(')');
                    break;
                case '[':
                    char_stack.push(']');
                    break;
                case '{':
                    char_stack.push('}');
                    break;
                default:
                    if (char_stack.empty() || char_stack.top() != c) {
                        return false;
                    }
                    char_stack.pop();
                    break;
            }
        }

        return char_stack.empty();
    }


    // Solution
    /**
     * LIFO (Last-In, First-Out): Stack
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    bool solution(string s) {
        if (s.length() % 2 != 0) {
            return false;
        }

        stack<char> st;
        unordered_map<char, char> matching_pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (matching_pairs.count(c)) {
                if (st.empty() || st.top() != matching_pairs[c]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.empty();
    }
};
