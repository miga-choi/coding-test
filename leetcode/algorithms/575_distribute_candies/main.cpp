#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class DistributeCandies {
public:
    int distributeCandies(vector<int> &candyType) {
        int candyTypeCount = 0;
        int candyTypeArray[200001] = {0};

        for (int i = 0; i < candyType.size(); i++) {
            if (!candyTypeArray[candyType[i] + 100000]) {
                candyTypeArray[candyType[i] + 100000] = 1;
                candyTypeCount++;
            }
        }

        return candyTypeCount < candyType.size() / 2 ? candyTypeCount : candyType.size() / 2;
    }

    // Solution
    int solution(vector<int>& candyType) {
        return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};
