#include <string>
using namespace std;

class AddStrings {
public:
  string addStrings(string num1, string num2) {
    string num = "";

    int num1Size = num1.size();
    int num2Size = num2.size();
    int numSize = num1Size > num2Size ? num1Size : num2Size;

    int up = 0;

    for (int i = 1; i <= numSize; i++) {
      int _num1 = num1Size - i >= 0 ? num1.at(num1Size - i) - '0' : 0;
      int _num2 = num2Size - i >= 0 ? num2.at(num2Size - i) - '0' : 0;

      int _num = _num1 + _num2 + up;

      if (_num > 9) {
        _num -= 10;
        up = 1;
      } else {
        up = 0;
      }

      num = to_string(_num) + num;
    }

    if (up > 0) {
      num = "1" + num;
    }

    return num;
  }

  // Best Solution
  string bestSolution(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while (i >= 0 || j >= 0 || carry) {
      long sum = 0;
      if (i >= 0) {
        sum += (num1[i] - '0');
        i--;
      }
      if (j >= 0) {
        sum += (num2[j] - '0');
        j--;
      }
      sum += carry;
      carry = sum / 10;
      sum = sum % 10;
      res = res + to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
