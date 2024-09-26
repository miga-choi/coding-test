class TwoSum {
  List<int> twoSum(List<int> nums, int target) {
    for (int i = 0; i < nums.length - 1; i++) {
      for (int j = i + 1; j < nums.length; j++) {
        if (nums[i] + nums[j] == target) {
          return [i, j];
        }
      }
    }
    return [];
  }
}

// Best Solution
// Best Solution 1: Brute Force
class BestSolution1 {
  List<int> twoSum(List<int> nums, int target) {
    int n = nums.length;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] + nums[j] == target) {
          return [i, j];
        }
      }
    }
    return []; // No solution found
  }
}

// Best Solution 2: Two-pass Hash Table
class BestSolution2 {
  List<int> twoSum(List<int> nums, int target) {
    Map<int, int> numMap = Map<int, int>();
    int n = nums.length;

    // Build the hash table
    for (int i = 0; i < n; i++) {
      numMap[nums[i]] = i;
    }

    // Find the complement
    for (int i = 0; i < n; i++) {
      int complement = target - nums[i];
      if (numMap.containsKey(complement) && numMap[complement] != i) {
        return [i, numMap[complement]!];
      }
    }

    return []; // No solution found
  }
}

// Best Solution 3: One-pass Hash Table
class BestSolution3 {
  List<int> twoSum(List<int> nums, int target) {
    Map<int, int> numMap = Map<int, int>();
    int n = nums.length;

    for (int i = 0; i < n; i++) {
      int complement = target - nums[i];
      if (numMap.containsKey(complement)) {
        return <int>[numMap[complement]!, i];
      }
      numMap[nums[i]] = i;
    }

    return <int>[]; // No solution found
  }
}
