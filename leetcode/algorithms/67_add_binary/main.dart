class AddBinary {
  /**
   * BigInt
   *
   * Complexities:
   *   N - Length of `a`
   *   M - Length of `b`
   *   - Time Complexity: O(max(N, M))
   *   - Space Complexity: O(max(N, M))
   */
  String addBinary(String a, String b) {
    return (BigInt.parse(a, radix: 2) + BigInt.parse(b, radix: 2)).toRadixString(2);
  }


  // Solution
  /**
   * Reverse Iteration
   *
   * Complexities:
   *   N - Length of `a`
   *   M - Length of `b`
   *   - Time Complexity: O(max(N, M))
   *   - Space Complexity: O(max(N, M))
   */
  String solution1(String a, String b) {
    StringBuffer sb = StringBuffer();

    int i = a.length - 1;
    int j = b.length - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
      int sum = carry;

      if (i >= 0) {
        if (a[i] == '1') sum++;
        i--;
      }

      if (j >= 0) {
        if (b[j] == '1') sum++;
        j--;
      }

      sb.write(sum % 2);

      carry = sum ~/ 2;
    }

    return sb.toString().split('').reversed.join('');
  }

  /**
   * BigInt
   *
   * Complexities:
   *   N - Length of `a`
   *   M - Length of `b`
   *   - Time Complexity: O(max(N, M))
   *   - Space Complexity: O(max(N, M))
   */
  String solution2(String a, String b) {
    BigInt numA = BigInt.parse(a, radix: 2);
    BigInt numB = BigInt.parse(b, radix: 2);

    return (numA + numB).toRadixString(2);
  }
}
