class ToLowerCase {
  String toLowerCase(String s) {
    String result = "";

    for (int i = 0; i < s.length; i++) {
      int code = s[i].codeUnitAt(0);
      if (code >= 65 && code <= 90) {
        result += String.fromCharCode(code + 32);
      } else {
        result += s[i];
      }
    }

    return result;
  }
}
