#include <string>
using namespace std;

class StudentAttendanceRecordI {
public:
    bool checkRecord(string s) {
        int absent = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                if (++absent > 1) {
                    return false;
                }
            } else if (i > 1 && s[i - 2] == 'L' && s[i - 1] == 'L' && s[i] == 'L') {
                return false;
            }
        }
        return true;
    }

    // Solution
    bool solution(string s) {
        int a = 0, l = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                a++;
            }
            if (s[i] == 'L') {
                l++;
            } else {
                l = 0;
            }
            if (a >= 2 || l > 2) {
                return false;
            }
        }
        return true;
    }
};
