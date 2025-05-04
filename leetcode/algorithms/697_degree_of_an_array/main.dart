class DegreeOfAnArray {
  int findShortestSubArray(List<int> nums) {
    Map<int, int> numsCountMap = Map<int, int>();
    Map<int, int> numsFirstIndexMap = Map<int, int>();
    int maxCount = 0;
    int minSubarrayLength = nums.length;

    for (int i = 0; i < nums.length; i++) {
      if (!numsCountMap.containsKey(nums[i])) {
        numsCountMap[nums[i]] = 0;
        numsFirstIndexMap[nums[i]] = i;
      }

      int count = numsCountMap[nums[i]]! + 1;
      numsCountMap[nums[i]] = count;
      if (count > maxCount) {
        maxCount = count;
        minSubarrayLength = i - numsFirstIndexMap[nums[i]]! + 1;
      } else if (count == maxCount) {
        int subarrayLength = i - numsFirstIndexMap[nums[i]]! + 1;
        if (subarrayLength < minSubarrayLength) {
          minSubarrayLength = subarrayLength;
        }
      }
    }

    return minSubarrayLength;
  }


  // Solution
  int solution(List<int> nums) {
    Map<int, List<int>> numOccurrences = {};
    int maxFrequency = 0;
    List<int> maxFreqNums = [];

    // Frequency calculation with tracking positions
    for (int i = 0; i < nums.length; i++) {
      if (!numOccurrences.containsKey(nums[i])) {
        // frequency, firstOccurrence, lastOccurrence
        numOccurrences[nums[i]] = [1, i, i];
      } else {
        numOccurrences[nums[i]]![0]++;
        numOccurrences[nums[i]]![2] = i;
      }

      int freq = numOccurrences[nums[i]]![0];
      if (freq > maxFrequency) {
        maxFrequency = freq;
        maxFreqNums = [nums[i]];
      } else if (freq == maxFrequency) {
        maxFreqNums.add(nums[i]);
      }
    }

    // Find shortest length among max frequency numbers
    int shortestLength = nums.length;
    for (int number in maxFreqNums) {
      int length = numOccurrences[number]![2] - numOccurrences[number]![1] + 1;
      if (length < shortestLength) {
        shortestLength = length;
      }
    }

    return shortestLength;
  }
}
