class AddBinary {
  String addBinary(String a, String b) {
    return (BigInt.parse(a, radix: 2) + BigInt.parse(b, radix: 2))
        .toRadixString(2);
  }


  // Solution
  String solution(String a, String b) {
    // result string
    String sum = "";

    // c = carry
    // i = last index of string a
    // j = last index of string b
    int i = a.length - 1, j = b.length - 1, c = 0;

    // i == 0 || j == 0 means run loop till we cover
    // both strings completely and c > 0 states
    // even if we covered both strings but carry still remains
    while (i >= 0 || j >= 0 || c > 0) {
      // carry=carry+ int value of a[i]
      if (i >= 0) {
        c += int.parse(a[i--]);
      }

      // carry = carry + int value of b[j]
      if (j >= 0) {
        c += int.parse(b[j--]);
      }

      // c % 2 means insert 0
      // if carry == 0 or carry == 2 (1+1)
      // because ('1'+'1'=0 in binary)
      // else insert 1 ('0'+'1'=1)
      sum = (c % 2).toString() + sum;

      // if c == 2 or 3 there is a carry
      // i.e 1 otherwise no carry
      // (3 in case if prev c=1 and a[i]=1 and b[i]=1)
      c = c ~/ 2;
    }

    return sum;
  }
}
