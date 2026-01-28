import java.math.BigInteger;

class AddBinary {
  /**
   * BigInteger
   *
   * Complexities:
   *   N - Length of `a`
   *   M - Length of `b`
   *   - Time Complexity: O(max(N, M))
   *   - Space Complexity: O(max(N, M))
   */
  public String addBinary(String a, String b) {
    return (new BigInteger(a, 2).add(new BigInteger(b, 2))).toString(2);
  }


  // Solution
  /**
   * Solution 1
   * 
   * Reverse
   *
   * Complexities:
   *   N - Length of `a`
   *   M - Length of `b`
   *   - Time Complexity: O(max(N, M))
   *   - Space Complexity: O(max(N, M))
   */
  public String solution1(String a, String b) {
    StringBuilder sb = new StringBuilder();

    int i = a.length() - 1;
    int j = b.length() - 1;

    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
      int sum = carry;

      if (i >= 0) {
        sum += a.charAt(i) - '0';
        i--;
      }

      if (j >= 0) {
        sum += b.charAt(j) - '0';
        j--;
      }

      sb.append(sum % 2);

      carry = sum / 2;
    }

    return sb.reverse().toString();
  }

  /**
   * Solution 2
   * 
   * BigInteger
   *
   * Complexities:
   *   N - Length of `a`
   *   M - Length of `b`
   *   - Time Complexity: O(max(N, M))
   *   - Space Complexity: O(max(N, M))
   */
  public String solution2(String a, String b) {
    return new BigInteger(a, 2).add(new BigInteger(b, 2)).toString(2);
  }
}
