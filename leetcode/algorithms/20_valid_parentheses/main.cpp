#include <string>
using namespace std;
#include <stack>

class ValidParentheses
{
public:
    bool isValid(string s)
    {
        char stack[s.length()];
        int index = -1;

        for (size_t i = 0; i < s.length(); i++)
        {
            if (s.at(i) == '(')
            {
                stack[++index] = ')';
            }
            else if (s.at(i) == '[')
            {
                stack[++index] = ']';
            }
            else if (s.at(i) == '{')
            {
                stack[++index] = '}';
            }
            else
            {
                if (index < 0 || stack[index] != s.at(i))
                {
                    return false;
                }
                index--;
            }
        }

        return index < 0;
    }


    // Best Solution
    bool bestSolution(string s)
    {
        stack<char> st; // create an empty stack to store opening brackets
        for (char c : s)
        { // loop through each character in the string
            if (c == '(' || c == '{' || c == '[')
            {               // if the character is an opening bracket
                st.push(c); // push it onto the stack
            }
            else
            {                                        // if the character is a closing bracket
                if (st.empty() ||                    // if the stack is empty or
                    (c == ')' && st.top() != '(') || // the closing bracket doesn't match the corresponding opening bracket at the top of the stack
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                {
                    return false; // the string is not valid, so return false
                }
                st.pop(); // otherwise, pop the opening bracket from the stack
            }
        }
        return st.empty(); // if the stack is empty, all opening brackets have been matched with their corresponding closing brackets,
                           // so the string is valid, otherwise, there are unmatched opening brackets, so return false
    }
};