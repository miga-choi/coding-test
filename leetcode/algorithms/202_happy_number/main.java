import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class HappyNumber {
  public boolean isHappy(int n) {
    if (n <= 1) {
      return true;
    }

    Map<Integer, Boolean> nMap = new HashMap<Integer, Boolean>();

    while (n > 1) {
      if (nMap.get(n) != null && nMap.get(n)) {
        return false;
      }
      nMap.put(n, true);
      List<Integer> nList = new ArrayList<Integer>();
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
  // Floyd's cycle-finding algorithm (Tortoise and the Hare algorithm)
  public int compute(int n) {
    int s = 0;
    while (n != 0) {
      s += (n % 10) * (n % 10);
      n = n / 10;
    }
    return s;
  }

  public boolean solution(int n) {
    int s = n, f = n; // slow , fast

    do {
      s = compute(s); // slow computes only once
      f = compute(compute(f)); // fast computes 2 times

      if (s == 1)
        return true; // if we found 1 then happy indeed !!!
    } while (s != f); // else at some point they will meet in the cycle

    return false; // it's a cycle , not happy at all !!!
  }
}
