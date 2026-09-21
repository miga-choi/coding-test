#include <bit>    // std::popcount (C++20)
#include <string> // std::string, std::to_string
#include <vector> // std::vector
using namespace std;

class BinaryWatch {
public:
    /**
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        // Hour
        for (int h = 0; h < 12; h++) {
            int hBitCount = 0;
            int H = h;

            while (H > 0) {
                if (H % 2 > 0) {
                    hBitCount++;
                }
                H >>= 1;
            }

            // Minute
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


    // Solution
    /**
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    vector<string> solution(int turnedOn) {
        vector<string> res;

        for (unsigned h = 0; h < 12; ++h) {
            int hb = popcount(h);
            if (hb > turnedOn) {
                continue;
            }

            for (unsigned m = 0; m < 60; ++m) {
                if (hb + popcount(m) == turnedOn) {
                    res.push_back(to_string(h) + ':' + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }

        return res;
    }
};
