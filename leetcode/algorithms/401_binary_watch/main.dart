class BinaryWatch {
  List<String> readBinaryWatch(int turnedOn) {
    List<String> result = List<String>.empty(growable: true);

    // Hour
    for (int h = 0; h < 12; h++) {
      int hBitCount = h.toRadixString(2).replaceAll("0", "").length;

      // Minute
      for (int m = 0; m < 60; m++) {
        int mBitCount = m.toRadixString(2).replaceAll("0", "").length;

        // Count
        if (hBitCount + mBitCount == turnedOn) {
          result.add(m < 10 ? "$h:0$m" : "$h:$m");
        }
      }
    }

    return result;
  }

  // Solution
  List<String> solution(int turnedOn) {
    List<String> res = [];

    for (int hour = 0; hour < 12; hour++) {
      for (int min = 0; min < 60; min++) {
        String temp = hour.toRadixString(2) + min.toRadixString(2);
        int count = 0;
        for (int i = 0; i < temp.length; i++) {
          if (temp[i] == '1') count++;
        }
        if (count == turnedOn) {
          res.add('$hour:${min.toString().padLeft(2, '0')}');
        }
      }
    }

    return res;
  }
}
