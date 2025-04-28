#include <sstream>
#include <string>
using namespace std;

class NumberOfSegmentsInAString {
public:
  int countSegments(string s) {
    int count = 0;
    int begin = 0;

    for (char c : s) {
      if (c != ' ') {
        begin = 1;
      }
      if (begin && c == ' ') {
        count++;
        begin = 0;
      }
    }

    return count + begin;
  }


  // Solution
  // Solution 1
  int solution1(string s) {
    int res = 0;

    s.push_back(' ');

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == ' ' && s[i - 1] != ' ') {
        ++res;
      }
    }

    return res;
  }

  // Solution 2: Brute force
  int solution2(string s) {
    istringstream iss(s);

    string word;
    int count = 0;

    while (iss >> word) {
      count++;
    }

    return count;
  }

  // Solution 3: Efficient Method
  int solution3(string s) {
    int count = 0;
    bool inSegment = false;

    for (char c : s) {
      if (c != ' ') {
        // If the character is not a space, we are in a segment
        if (!inSegment) {
          inSegment = true;
          count++;
        }
      } else {
        // If the character is a space, we are not in a segment
        inSegment = false;
      }
    }

    return count;
  }
};
