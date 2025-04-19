class ExcelSheetColumnTitle {
  String convertToTitle(int columnNumber) {
    String result = "";
    while (columnNumber > 0) {
      columnNumber -= 1;
      result = String.fromCharCode(columnNumber % 26 + 65) + result;
      columnNumber = (columnNumber / 26).floor();
    }
    return result;
  }


  // Solution
  String solution(int columnNumber) {
    StringBuffer stringBuffer = StringBuffer();
    while (columnNumber > 0) {
      int reminder = (columnNumber - 1) % 26;
      stringBuffer.write(String.fromCharCode(reminder + 'A'.codeUnitAt(0)));
      columnNumber = (columnNumber - 1) ~/ 26;
    }
    return stringBuffer.toString().split('').reversed.join();
  }
}
