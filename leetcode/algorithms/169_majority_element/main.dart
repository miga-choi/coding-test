class MajorityElement {
  /**
   * Boyer-Moore Voting Algorithm
   *
   * Complexities:
   *   N - `numsSize`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int majorityElement(List<int> nums) {
    int result = 0;
    int count = 0;

    for (int num in nums) {
      if (count == 0) {
        result = num;
      }
      if (result == num) {
        count++;
      } else {
        count--;
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Boyer-Moore Voting Algorithm
   *
   * Complexities:
   *   N - `numsSize`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(List<int> nums) {
    int candidate = 0;
    int count = 0;

    for (int num in nums) {
      if (count == 0) {
        candidate = num;
      }

      if (num == candidate) {
        count++;
      } else {
        count--;
      }
    }

    return candidate;
  }

  /**
   * Solution 2
   * 
   * Sorting
   *
   * Complexities:
   *   N - `numsSize`
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(1)
   */
  int solution2(List<int> nums) {
    nums.sort();
    return nums[nums.length ~/ 2];
  }

  /**
   * Solution 3
   * 
   * Hash Map
   *
   * Complexities:
   *   N - `numsSize`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  int solution3(List<int> nums) {
    Map<int, int> counts = {};
    int majorityCount = nums.length ~/ 2;

    for (int num in nums) {
      counts[num] = (counts[num] ?? 0) + 1;
      if (counts[num]! > majorityCount) {
        return num;
      }
    }
    return -1;
  }
}
