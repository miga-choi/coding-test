public class ValidParentheses
{
    public bool IsValid(string s)
    {
        Stack<char> stack = new Stack<char>();

        foreach (char c in s)
        {
            if (c == '(')
            {
                stack.Push(')');
            }
            else
            if (c == '[')
            {
                stack.Push(']');
            }
            else
            if (c == '{')
            {
                stack.Push('}');
            }
            else
            {
                if (stack.Count <= 0 || stack.Pop() != c)
                {
                    return false;
                }
            }
        }

        return stack.Count <= 0;
    }

    // Best Solution
    // Best Solution 1: Stack
    public bool bestSolution1(string s)
    {
        // Get ready initial state (enforce element type)
        var k = new Stack<char>();
        // Evaluate each character for potential mismatch 
        foreach (char c in s)
        {
            // Push closing round bracket onto the stack
            if (c == '(') { k.Push(')'); continue; }
            // Push closing curly bracket onto the stack
            if (c == '{') { k.Push('}'); continue; }
            // Push closing square bracket onto the stack
            if (c == '[') { k.Push(']'); continue; }
            // Look out for imbalanced strings or mismatches
            if (k.Count == 0 || c != k.Pop()) return false;
        }
        // Empty stack means string is valid and invalid otherwise
        return k.Count == 0;
    }

    // Best Solution 2: Replace
    public bool bestSolution2(string s)
    {
        while (s.Contains("()") || s.Contains("[]") || s.Contains("{}"))
        {
            s = s.Replace("()", "").Replace("[]", "").Replace("{}", "");
        }

        return s.Length == 0;
    }

    // Best Solution 3: Stack
    public bool bestSolution3(string s)
    {
        Dictionary<char, char> bracketsMap = new Dictionary<char, char>{
            {'{',  '}'},
            {'(',  ')'},
            {'[',  ']'},
        };
        Stack<char> openBrackets = new Stack<char>();

        foreach (char bracket in s)
        {
            if (bracketsMap.ContainsKey(bracket))
            {
                openBrackets.Push(bracket);
            }
            else
            {
                if (openBrackets.Count == 0)
                {
                    return false;
                }
                if (bracketsMap[openBrackets.Pop()] == bracket)
                {
                    continue;
                };
                return false;
            }
        }
        return openBrackets.Count == 0;
    }
}