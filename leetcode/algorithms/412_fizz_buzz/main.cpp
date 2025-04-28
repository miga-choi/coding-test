#include <vector>
using namespace std;

class FizzBuzz {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                result.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                result.push_back("Fizz");
            } else if (i % 5 == 0) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i));
            }
        }

        return result;
    }


    // Solution
    vector<string> solution(int n) {
        vector<string> res(n);

        for (int i = 1; i <= n; i++) {
            res[i - 1] = to_string(i);
        }

        for (int i = 2; i < n; i += 3) {
            res[i] = "Fizz";
        }

        for (int i = 4; i < n; i += 5) {
            res[i] = "Buzz";
        }

        for (int i = 14; i < n; i += 15) {
            res[i] = "FizzBuzz";
        }

        return res;
    }
};
