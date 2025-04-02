#include <string>
using namespace std;

class RobotReturnToOrigin {
public:
    bool judgeCircle(string moves) {
        int landscape = 0, portrait = 0;

        for (char c : moves) {
            switch (c) {
                case 'U':
                    portrait++;
                    break;
                case 'D':
                    portrait--;
                    break;
                case 'R':
                    landscape++;
                    break;
                case 'L':
                    landscape--;
                    break;
            }
        }
        
        return !landscape && !portrait;
    }

    // Solution
    bool solution(string moves) {
        int v = 0;
        int h = 0;
        for (char ch : moves) {
            switch (ch) {
                case 'U':
                    v++;
                    break;
                case 'D':
                    v--;
                    break;
                case 'R':
                    h++;
                    break;
                case 'L':
                    h--;
                    break;
            }
        }
        return v == 0 && h == 0;
    }
};
