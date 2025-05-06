class LicenseKeyFormatting {
  String licenseKeyFormatting(String s, int k) {
    String result = "";
    List<String> sArray = s.replaceAll("-", "").split("");

    for (int i = 1; i <= sArray.length; i++) {
      if (i < sArray.length && (i % k) == 0) {
        result = "-${sArray[sArray.length - i].toUpperCase()}$result";
      } else {
        result = "${sArray[sArray.length - i].toUpperCase()}$result";
      }
    }

    return result;
  }


  // Solution
  String solution(String s, int k) {
    final _dash = '-'.codeUnits[0];

    var result = <int>[];
    var currentGroupLength = 0;

    for (var char in s.codeUnits.reversed) {
      if (char == _dash) {
        continue;
      }
      result.add(char);
      currentGroupLength++;
      if (currentGroupLength == k) {
        result.add(_dash);
        currentGroupLength = 0;
      }
    }

    if (!result.isEmpty && result.last == _dash) {
      result.removeLast();
    }

    return String.fromCharCodes(result.reversed).toUpperCase();
  }
}
