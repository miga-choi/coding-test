#include <vector>
#include <limits>
#include <set>
using namespace std;

class ThirdMaximumNumber {
public:
  int thirdMax(vector<int> &nums) {
    int first = nums[0];
    long second = LONG_MIN;
    long thrid = LONG_MIN;

    for (int num : nums) {
      if (num > first) {
        thrid = second;
        second = first;
        first = num;
      } else if (num < first && num > second) {
        thrid = second;
        second = num;
      } else if (num < second && num > thrid) {
        thrid = num;
      }
    }

    return thrid == LONG_MIN ? first : thrid;
  }


  // Solution
  // Solution 1: Track the largest three values in a set
  int solution1(vector<int> &nums) {
    set<int> top3;

    for (int num : nums) {
      top3.insert(num);
      if (top3.size() > 3) {
        top3.erase(top3.begin());
      }
    }

    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
  }

  // Solution 2: Alternatively
  int solution2(vector<int> &nums) {
    set<int> top3;

    for (int num : nums) {
      if (top3.insert(num).second && top3.size() > 3) {
        top3.erase(top3.begin());
      }
    }

    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
  }
};
