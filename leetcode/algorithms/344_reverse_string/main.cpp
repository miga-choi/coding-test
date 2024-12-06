#include <vector>
using namespace std;

class ReverseString
{
public:
    void reverseString(vector<char> &s) {
        for (int i = 0; i < s.size() / 2; i++) {
            char temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }
    }

    // Best Solution
    void bestSolution(vector<char> &s) {
        int i = 0;
        int j = s.size() - 1;

        while (i <= j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};
