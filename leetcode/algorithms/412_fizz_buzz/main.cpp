#include <array>   //std::array
#include <string>  // std::string
#include <utility> // std::pair
#include <vector>  // std::vector
using namespace std;

class FizzBuzz {
public:
    /**
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
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
    /**
     * Solution 1
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    vector<string> solution1(int n) {
        vector<string> res;
        res.reserve(n);

        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                res.emplace_back("FizzBuzz");
            } else if (i % 3 == 0) {
                res.emplace_back("Fizz");
            } else if (i % 5 == 0) {
                res.emplace_back("Buzz");
            } else {
                res.push_back(std::to_string(i));
            }
        }

        return res;
    }

    /**
     * Solution 2
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    vector<string> solution2(int n) {
        vector<string> res;
        res.reserve(n);
        int c3 = 0, c5 = 0;

        for (int i = 1; i <= n; ++i) {
            ++c3; ++c5;

            if (c3 == 3 && c5 == 5) {
                res.emplace_back("FizzBuzz");
            } else if (c3 == 3) {
                res.emplace_back("Fizz");
            } else if (c5 == 5) {
                res.emplace_back("Buzz");
            } else {
                res.push_back(std::to_string(i));
            }

            if (c3 == 3) {
                c3 = 0;
            }
            if (c5 == 5) {
                c5 = 0;
            }
        }

        return res;
    }

    /**
     * Solution 3
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    vector<string> solution3(int n) {
        static const array<pair<int, const char*>, 2> RULES{{
            {3, "Fizz"},
            {5, "Buzz"},
        }};

        vector<string> res;
        res.reserve(n);

        for (int i = 1; i <= n; ++i) {
            string s;

            for (const auto &[d, word] : RULES) {
                if (i % d == 0) {
                    s += word;
                }
            }

            res.push_back(s.empty() ? to_string(i) : move(s));
        }

        return res;
    }
};
