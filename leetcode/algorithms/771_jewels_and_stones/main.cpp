#include <string>
#include <unordered_set>
using namespace std;

class JewelsAndStones {
public:
    int numJewelsInStones(string jewels, string stones) {
        int numsArray[128] = {};
        for (char jewel : jewels) {
            numsArray[jewel] = 1;
        }

        int count = 0;
        for (char stone : stones) {
            count += numsArray[stone];
        }

        return count;
    }


    // Solution
    // Solution 1: unordered_set
    int solution1(string jewels, string stones) {
        int res = 0;
        unordered_set<char> jewelsSet(jewels.begin(), jewels.end());

        for (char s : stones) {
            if (jewelsSet.count(s)) {
                res++;
            }
        }

        return res;
    }

    // Solution 2: count
    int solution2(string jewels, string stones) {
        int num = 0;

        for (int i = 0; i < jewels.size(); i++) {
            num += count(stones.begin(), stones.end(), jewels[i]);
        }

        return num;
    }
};
