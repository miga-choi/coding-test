class Solution {

  public int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }
    int low = 1;
    int high = x;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (mid == x / mid) {
        return mid;
      } else if (mid > x / mid) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return high;
  }

  // Best Solution
  public int bestSolution(int x) {
    if (x == 0) {
      return 0;
    }
    int first = 1, last = x;
    while (first <= last) {
      int mid = first + (last - first) / 2;
      if (mid == x / mid) {
        return mid;
      } else if (mid > x / mid) {
        last = mid - 1;
      } else {
        first = mid + 1;
      }
    }
    return last;
  }
}
