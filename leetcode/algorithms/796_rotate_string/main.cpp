#include <string>
using namespace std;

class RotateString {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        return (s + s).find(goal) != string::npos;
    }


    // Solution
    // Solution 1
    bool solution1(string s, string goal) {
        int sLength = s.size();

        if (sLength != goal.size()) {
            return false;
        }

        // Try all possible rotations of the string
        for (int rotationCount = 0; rotationCount < sLength; ++rotationCount) {
            // Perform one rotation
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) {
                return true;
            }
        }

        return false;
    }

    // Solution 2
    bool solution2(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
