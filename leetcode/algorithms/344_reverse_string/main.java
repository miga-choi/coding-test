import java.util.Stack;

class ReverseString {
    public void reverseString(char[] s) {
        for (int i = 0; i < s.length / 2; i++) {
            char temp = s[i];
            s[i] = s[s.length - 1 - i];
            s[s.length - 1 - i] = temp;
        }
    }


    // Solution
    // Solution 1: Two Pointer's
    public void solution1(char[] s) {
        int i = 0;
        int j = s.length - 1;

        while (i <= j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }

    // Solution 2: Recursive Call
    public void solution2(char[] s) {
        int i = 0;
        int j = s.length - 1;
        solve(s, i, j);
    }

    public void solve(char[] s, int i, int j) {
        if (i >= j) {
            return;
        }
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        solve(s, ++i, --j);
    }

    // Solution 3: Stack
    public void solution3(char[] s) {
        Stack<Character> st = new Stack<>();
        String str = new String(s);
        for (int i = 0; i < str.length(); i++) {
            st.push(s[i]);
        }
        char ans[] = new char[s.length];
        int i = 0;
        while (st.size() > 0) {
            s[i++] = st.pop();
        }
        for (int j = 0; j < str.length(); j++) {
            ans[j] = str.charAt(j);
        }
    }
}
