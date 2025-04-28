#include <unordered_set>
#include <vector>
using namespace std;

class FindAllNumbersDisappearedInAnArray {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> numArray(nums.size(), 0);

    for (int num : nums) {
      numArray[num - 1] = 1;
    }

    vector<int> result;

    for (int i = 1; i <= nums.size(); i++) {
      if (!numArray[i] - 1) {
        result.push_back(i);
      }
    }

    return result;
  }

  
  // Solution
  // Solution 1: Brute-Force
  vector<int> solution1(vector<int>& nums) {
    vector<int> ans;

    for (int i = 1; i <= size(nums); i++) {
      // linear search in nums for each i
      if (find(begin(nums), end(nums), i) == end(nums)) {
        ans.push_back(i);
      }
    }

    return ans;
  }

  // Solution 2: Sort & Binary-Search
  vector<int> solution2(vector<int>& nums) {
    sort(begin(nums), end(nums));
    vector<int> ans;

    for (int i = 1; i <= size(nums); i++) {
      // binary search in nums for each i
      if (!binary_search(begin(nums), end(nums), i)) {
        ans.push_back(i);
      }
    }

    return ans;
  }

  // Solution 3: HashSet
  vector<int> solution3(vector<int>& nums) {
    // insert every nums[i] in hashset
    unordered_set<int> s(begin(nums), end(nums));

    vector<int> ans(size(nums) - size(s));

    for (int i = 1, j = 0; i <= size(nums); i++) {
      // add all elements not found in hashset to ans
      if (!s.count(i)) {
        ans[j++] = i;
      }
    }

    return ans;
  }

  // Solution 4: Boolean array
  vector<int> solution4(vector<int>& nums) {
    vector<bool> seen(size(nums) + 1);
    vector<int> ans;

    for (auto c : nums) {
      seen[c] = true;
    }

    for (int i = 1; i <= size(nums); i++) {
      if (!seen[i]) {
        ans.push_back(i);
      }
    }

    return ans;
  }

  // Solution 5: Placing Elements at Correct Index - Space Optimized
  vector<int> solution5(vector<int>& nums) {
    vector<int> ans;

    for (auto &c : nums) {
      while (nums[c - 1] != c) {
        // swap till correct index place of c is not occupied by c itself
        swap(c, nums[c - 1]);
      }
    }

    for (int i = 1; i <= size(nums); i++) {
      // correct index place of i is not occupied by i itself
      if (i != nums[i - 1]) {
        ans.push_back(i);
      }
    }

    return ans;
  }

  // Solution 6: Mark as seen by Negation - Space Optimized
  vector<int> solution6(vector<int>& nums) {
    vector<int> ans;

    for (int c : nums) {
      // mark c is present by negating nums[c-1]
      nums[abs(c) - 1] = -abs(nums[abs(c) - 1]);
    }

    for (int i = 0; i < size(nums); i++) {
      // nums[i] > 0 means i+1 isnt present in nums
      if (nums[i] > 0) {
        ans.push_back(i + 1);
      }
    }

    return ans;
  }
};
