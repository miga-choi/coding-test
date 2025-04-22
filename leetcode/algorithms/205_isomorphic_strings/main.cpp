#include<string>
using namespace std;

class RemoveLinkedListElements {
public:
    bool isIsomorphic(string s, string t) {
        char sCharArray[256] = {0};
        char tCharArray[256] = {0};

        for (int i = 0; s[i] != '\0' && t[i] != '\0'; i++) {
            if (sCharArray[s[i]] == 0 && tCharArray[t[i]] == 0) {
                sCharArray[s[i]] = t[i];
                tCharArray[t[i]] = s[i];
            } else if (sCharArray[s[i]] != t[i] || tCharArray[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }


    // Solution
    bool solution(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
