#include <vector>
using namespace std;

class OneBitAndTwoBitCharacters {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;

        while (i < bits.size() - 1) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                i += 1;
            }
        }

        return i == bits.size() - 1;
    }


    // Solution
    // Solution 1: Increment Pointer
    bool solution1(vector<int>& bits) {
        int i = 0;

        while (i < bits.size() - 1) {
            i += bits[i] + 1;
        }

        return i == bits.size() - 1;
    }

    // Solution 2: Greedy
    bool solution2(vector<int>& bits) {
        int i = bits.size() - 2;

        while (i >= 0 && bits[i] > 0) {
            i--;
        }

        return (bits.size() - i) % 2 == 0;
    }
};
