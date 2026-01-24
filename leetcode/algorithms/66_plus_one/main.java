import java.util.Arrays;

class PlusOne {
  /**
   * Complexities:
   *   N - Length of `digits`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public int[] plusOne(int[] digits) {
    for (int i = digits.length - 1; i >= 0; i--) {
      digits[i]++;

      if (digits[i] < 10) {
        return digits;
      }

      digits[i] -= 10;
    }

    int[] result = new int[digits.length + 1];
    Arrays.fill(result, 0);
    result[0] = 1;

    return result;
  }


  // Solution
  /**
   * Complexities:
   *   N - Length of `digits`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public int[] solution(int[] digits) {
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
}
