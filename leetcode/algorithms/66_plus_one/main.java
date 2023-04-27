import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {

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
  public int[] bestSolution(int[] digits) {
    for (int i = digits.length - 1; i >= 0; i--) {
      if (digits[i] < 9) {
        digits[i]++;
        return digits;
      }
      digits[i] = 0;
    }

    digits = new int[digits.length + 1];
    digits[0] = 1;
    return digits;
  }
}
