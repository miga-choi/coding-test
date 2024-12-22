#include <bitset>
#include <string>
#include <vector>
using namespace std;

class BinaryWatch {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        // H
        for (int h = 0; h < 12; h++) {
            int hBitCount = 0;
            int H = h;

            while (H > 0) {
                if (H % 2 > 0) {
                    hBitCount++;
                }
                H >>= 1;
            }

            for (int m = 0; m < 60; m++) {
                int mBitCount = 0;
                int M = m;

                while (M > 0) {
                    if (M % 2 > 0) {
                        mBitCount++;
                    }
                    M >>= 1;
                }

                if (hBitCount + mBitCount == turnedOn) {
                    result.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }

        return result;
    }

    // Best Solution
    vector<string> bestSolution(int turnedOn) {
        vector<string> rs;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (bitset<10>(h << 6 | m).count() == turnedOn) {
                    rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return rs;
    }
};
