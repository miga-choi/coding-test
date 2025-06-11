#include <vector>
using namespace std;

class FindSmallestLetterGreaterThanTarget {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) {
            return letters.front();
        }

        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] > target) {
                return letters[i];
            }
        }

        return letters.front();
    }


    // Solution
    // Solution 1
    char solution1(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;
    }

    // Solution 2
    char solution2(vector<char>& letters, char target) {
        if (letters.back() <= target) {
            return letters.front();
        }

        int low = 0, high = letters.size() - 1;

        while (low < high) {
            auto mid = low + (high - low) / 2;
            if (target < letters[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return letters[low];
    }
};
