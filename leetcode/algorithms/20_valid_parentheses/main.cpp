#include <string>
using namespace std;
#include <stack>

class ValidParentheses {
public:
    bool isValid(string s) {
        char stack[s.length()];
        int index = -1;

        for (size_t i = 0; i < s.length(); i++) {
            if (s.at(i) == '(') {
                stack[++index] = ')';
            } else if (s.at(i) == '[') {
                stack[++index] = ']';
            } else if (s.at(i) == '{') {
                stack[++index] = '}';
            } else {
                if (index < 0 || stack[index] != s.at(i)) {
                    return false;
                }
                index--;
            }
        }

        return index < 0;
    }


    // Solution
    bool solution(string s) {
        // create an empty stack to store opening brackets
        stack<char> st;

        // loop through each character in the string
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                // if the character is an opening bracket
                // push it onto the stack
                st.push(c);
            } else {
                // if the character is a closing bracket
                if (
                    // if the stack is empty or
                    st.empty() ||                    
                    // the closing bracket doesn't match the corresponding opening bracket at the top of the stack
                    (c == ')' && st.top() != '(') || 
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    // the string is not valid, so return false
                    return false; 
                }
                // otherwise, pop the opening bracket from the stack
                st.pop();
            }
        }

        // if the stack is empty, all opening brackets have been matched with their corresponding closing brackets,
        // so the string is valid, otherwise, there are unmatched opening brackets, so return false
        return st.empty(); 
    }
};
