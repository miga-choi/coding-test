#include <string>
using namespace std;

class ToLowerCase {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
        return s;
    }


    // Solution
    string solution(string s) {
        for (char& c : s) {
            if (c >= 'A' && c <= 'Z') {
                c += 32;
            }
        }
        return s;
    }
};
