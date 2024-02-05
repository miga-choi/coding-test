import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class PlusOne {
  public int[] plusOne(int[] digits) {
    List<Integer> result = Arrays
        .stream(digits)
        .boxed()
        .collect(Collectors.toList());
    for (int i = result.size() - 1; i >= 0; i--) {
      result.set(i, result.get(i) + 1);
      if (result.get(i) > 9) {
        result.set(i, 0);
      } else {
        return result.stream().mapToInt(v_ -> v_).toArray();
      }
    }
    result.add(0, 1);
    return result.stream().mapToInt(v_ -> v_).toArray();
  }


  // Best Solution
  // Best Solution 1:
  public int[] bestSolution1(int[] digits) {
    int n = digits.length;
    for (int i = n - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits;
      }

      digits[i] = 0;
    }

    int[] newNumber = new int[n + 1];
    newNumber[0] = 1;

    return newNumber;
  }

  // Best Solution 2:
  public int[] bestSolution2(int[] digits) {
    int carry = 1;
    for (int i = digits.length - 1; i >= 0; i--) {
      digits[i] += carry;
      if (digits[i] <= 9) {
        // early return
        return digits;
      }
      digits[i] = 0;
    }
    int[] ret = new int[digits.length + 1];
    ret[0] = 1;
    return ret;
  }
}
