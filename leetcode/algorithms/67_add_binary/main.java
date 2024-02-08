import java.math.BigInteger;

class AddBinary {
  public String addBinary(String a, String b) {
    return (new BigInteger(a, 2).add(new BigInteger(b, 2))).toString(2);
  }


  // Best Solution
  // Best Solution 1:
  public String bestSolution1(String a, String b) {
    StringBuilder sb = new StringBuilder();
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    while (i >= 0 || j >= 0) {
      int sum = carry;
      if (i >= 0) {
        sum += a.charAt(i--) - '0';
      }
      if (j >= 0) {
        sum += b.charAt(j--) - '0';
      }
      sb.append(sum % 2);
      carry = sum / 2;
    }
    if (carry != 0) {
      sb.append(carry);
    }
    return sb.reverse().toString();
  }

  // Best Solution 2:
  public String bestSolution2(String a, String b) {
    StringBuilder res = new StringBuilder();
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0) {
      int sum = carry;
      if (i >= 0) {
        sum += a.charAt(i--) - '0';
      }
      if (j >= 0) {
        sum += b.charAt(j--) - '0';
      }
      carry = sum > 1 ? 1 : 0;
      res.append(sum % 2);
    }
    if (carry != 0) {
      res.append(carry);
    }
    return res.reverse().toString();
  }
}
