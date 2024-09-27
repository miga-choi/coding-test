class RomanToInteger {
  int romanToInt(String s) {
    Map<String, int> romanMap = Map<String, int>();
    romanMap["I"] = 1;
    romanMap["V"] = 5;
    romanMap["X"] = 10;
    romanMap["L"] = 50;
    romanMap["C"] = 100;
    romanMap["D"] = 500;
    romanMap["M"] = 1000;

    s = s
        .replaceAll("CM", "DCCCC")
        .replaceAll("CD", "CCCC")
        .replaceAll("XC", "LXXXX")
        .replaceAll("XL", "XXXX")
        .replaceAll("IX", "VIIII")
        .replaceAll("IV", "IIII");

    int result = 0;
    for (String c in s.split("")) {
      result += romanMap[c] ?? 0;
    }

    return result;
  }

  // Best Solution
  int bestSolution(String s) {
    final romans = <String, int>{
      'IV': 4,
      'IX': 9,
      'XL': 40,
      'XC': 90,
      'CD': 400,
      'CM': 900,
      'I': 1,
      'V': 5,
      'X': 10,
      'L': 50,
      'C': 100,
      'D': 500,
      'M': 1000,
    };

    int result = 0;

    for (final roman in romans.entries) {
      // Get count of roman number in string
      final count = roman.key.allMatches(s).length;
      // Multiply count to value
      result += roman.value * count;
      // Remove the Roman number from the string so as dont repeat I in IV and IX, etc.
      s = s.replaceAll(roman.key, '');
    }

    return result;
  }
}
