#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class ValidParentheses {
public:
    /**
     * LIFO (Last-In, First-Out): Stack
     * 
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
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
     * 
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    bool solution(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } else {
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};
