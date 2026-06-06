import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class HappyNumber {
  /**
   * Hash Map
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(logᴺ)
   */
  public boolean isHappy(int n) {
    if (n <= 1) {
      return true;
    }

    Map<Integer, Boolean> nMap = new HashMap<>();

    while (n > 1) {
      if (nMap.get(n) != null && nMap.get(n)) {
        return false;
      }

      nMap.put(n, true);
      List<Integer> nList = new ArrayList<>();

      for (int i = 0; i < String.valueOf(n).length(); i++) {
        nList.add(String.valueOf(n).charAt(i) - '0');
      }

      n = nList
          .stream()
          .reduce(0, (total_, current_) -> (int) (total_ + Math.pow(current_, 2)));

      if (n == 1) {
        return true;
      }
    }

    return false;
  }


  // Solution
  /**
   * Floyd's Cycle-Finding Algorithm
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(1)
   */
  private int getNext(int n) {
    int totalSum = 0;

    while (n > 0) {
      int digit = n % 10;
      n = n / 10;
      totalSum += digit * digit;
    }

    return totalSum;
  }

  public boolean solution(int n) {
    int slow = n;
    int fast = getNext(n);

    while (fast != 1 && slow != fast) {
      slow = getNext(slow);
      fast = getNext(getNext(fast));
    }

    return fast == 1;
  }
}
