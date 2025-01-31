#include <string>
using namespace std;

class DetectCapital {
public:
    bool detectCapitalUse(string word) {
        for (int i = 1; i < word.size(); i++) {
            if (i > 1) {
                if (word[i] > 'Z' && word[i - 1] < 'a') {
                    return false;
                } else if (word[i] < 'a' && word[i - 1] > 'Z') {
                    return false;
                }
            } else {
                if (word[i - 1] > 'Z' && word[i] < 'a') {
                    return false;
                }
            }
        }
        return true;
    }

    // Solution
    bool solution(string word) {
        if (word.length() < 2) {
            return true;
        }
        if (isupper(word[0]) && isupper(word[1])) {
            for (int i = 2; i < word.length(); i++) {
                if (islower(word[i])) {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < word.length(); i++) {
                if (isupper(word[i])) {
                    return false;
                }
            }
        }
        return true;
    }
};
