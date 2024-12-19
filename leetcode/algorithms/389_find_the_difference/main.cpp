#include <string>
using namespace std;

class FindTheDifference {
public:
    char findTheDifference(string s, string t) {
        int alphabetNumArray[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            alphabetNumArray[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            if (alphabetNumArray[t[i] - 'a'] == 0) {
                return t[i];
            } else {
                alphabetNumArray[t[i] - 'a']--;
            }
        }

        return ' ';
    }

    // Best Solution
    char bestSolution(string s, string t) {
        // Passing the diff: (t[i]-s[i]) to t[i+1]
        for (int i = 0; i < s.size(); i++) {
            t[i + 1] += t[i] - s[i];
        }

        // The diff will be carried over to the last element eventually
        return t[t.size() - 1];
    }
};
