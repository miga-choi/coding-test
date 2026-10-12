#include <cstddef> // std::size_t
#include <sstream> // std::istringstream
#include <string>  // std::string
using namespace std;

class NumberOfSegmentsInAString {
public:
  /**
   * Status flag
   * 
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
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
  /**
   * Solution 1
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(string s) {
      int count = 0;

      for (size_t i = 0; i < s.size(); ++i) {
          if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
              ++count;
          }
      }

      return count;
  }

  /**
   * Solution 2
   * 
   * Status Flag
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution2(string s) {
      int count = 0;
      bool inSeg = false;

      for (char c : s) {
          if (c == ' ') {
              inSeg = false;
          } else if (!inSeg) {
              inSeg = true;
              ++count;
          }
      }

      return count;
  }

  /**
   * Solution 3
   * 
   * std::istringstream
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  int solution3(string s) {
      istringstream iss(s);
      string word;
      int count = 0;

      while (iss >> word) {
          ++count;
      }

      return count;
  }
};
