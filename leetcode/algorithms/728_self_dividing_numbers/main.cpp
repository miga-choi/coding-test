#include <vector>
using namespace std;

class SelfDividingNumbers {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for (int i = left; i <= right; i++) {
            int v = i;

            while (v > 0) {
                if (v % 10 == 0 || i % (v % 10) > 0) {
                    break;
                }

                v /= 10;
            }

            if (v == 0) {
                result.push_back(i);
            }
        }

        return result;
    }


    // Solution
    vector<int> solution(int left, int right) {
        vector<int> res;

        for (int i = left, n = 0; i <= right; i++) {
            for (n = i; n > 0; n /= 10) {
                if (!(n % 10) || i % (n % 10)) {
                    break;
                }
            }

            if (!n) {
                res.push_back(i);
            }
        }

        return res;
    }
};
