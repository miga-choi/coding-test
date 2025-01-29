#include <cmath>
#include <vector>
using namespace std;

class FibonacciNumber {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

    // Solution 1: Fastest Approach
    int solution1(int n) {
        int fib_nums[47] = {
            0,         1,         1,         2,          3,         5,
            8,         13,        21,        34,         55,        89,
            144,       233,       377,       610,        987,       1597,
            2584,      4181,      6765,      10946,      17711,     28657,
            46368,     75025,     121393,    196418,     317811,    514229,
            832040,    1346269,   2178309,   3524578,    5702887,   9227465,
            14930352,  24157817,  39088169,  63245986,   102334155, 165580141,
            267914296, 433494437, 701408733, 1134903170, 1836311903
        };
        return fib_nums[n];
    }

    // Solution 2: Recursive Approach
    int solution2(int n) {
        if (n <= 1) {
            return n;
        }
        return solution2(n - 1) + solution2(n - 2);
    }

    // Solution 3: Dynamic Programming Tabulation
    int solution3(int n) {
        if (n <= 1) {
            return n;
        }
        int f[n + 1];
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
    
    // Solution 4: Dynamic Programming Memoization (Top-Down)
    static vector<int> dp;

    FibonacciNumber() {
        if (dp.empty()) {
            dp.resize(31, -1);
        }
    }

    int solution4(int n) {
        if (n <= 1) {
            return n;
        }

        // Temporary variables to store values of fib(n-1) & fib(n-2)
        int first, second;

        if (dp[n - 1] != -1) {
            first = dp[n - 1];
        } else {
            first = fib(n - 1);
        }

        if (dp[n - 2] != -1) {
            second = dp[n - 2];
        } else {
            second = fib(n - 2);
        }

        // Memoization
        return dp[n] = first + second;
    }

    // Solution 5: Math Formula
    int solution5(int n) {
        double sqrt5 = sqrt(5);
        double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
        return round(fibN / sqrt5);
    }
};
