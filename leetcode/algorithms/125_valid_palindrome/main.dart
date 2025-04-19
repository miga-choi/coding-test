class ValidPalindrome {
  bool isPalindrome(String s) {
    int prefix = 0;
    int suffix = s.length - 1;
    final RegExp alphanumeric = RegExp(r'^[a-zA-Z0-9]$', caseSensitive: false);

    while (prefix < suffix) {
      if (!alphanumeric.hasMatch(s[prefix])) {
        prefix++;
        continue;
      }
      if (!alphanumeric.hasMatch(s[suffix])) {
        suffix--;
        continue;
      }
      if (!(s[prefix].toLowerCase() == s[suffix].toLowerCase())) {
        return false;
      }
      prefix++;
      suffix--;
    }

    return true;
  }


  // Solution
  bool solution(String s) {
    s = s.toLowerCase();

    String bag = '';

    for (int i = 0; i < s.length; i++) {
      int a = s.codeUnitAt(i);
      if ((a >= 48 && a < 58) || (a >= 97 && a <= 122)) {
        bag += s[i];
      }
    }

    int r = bag.length - 1;
    bool pal = true;
    if (bag.length <= 1) {
      return true;
    } else {
      for (int j = 0; j < (bag.length / 2).floor(); j++) {
        if (bag[j] != bag[r]) {
          pal = false;
          break;
        }
        r--;
      }
    }

    return pal;
  }
}
