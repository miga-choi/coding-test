#include <string>
using namespace std;

class Base7 {
public:
    string convertToBase7(int num) {
        if (!num) {
            return "0";
        }

        int negative = 0;

        if (num < 0) {
            negative = 1;
            num *= -1;
        }

        string result = "";

        while (num > 0) {
            result = to_string(num % 7) + result;
            num /= 7;
        }

        return negative ? "-" + result : result;
    }

    // Solution 1: Recursive
    string solution1(int num) {
        if (num < 0) {
            return "-" + solution1(-num);
        }
        if (num < 7) {
            return to_string(num);
        }
        return solution1(num / 7) + to_string(num % 7);
    }

    // Solution 2: Iterative
    string solution2(int num) {
        int x = abs(num);
        string res;
        do {
            res = to_string(x % 7) + res;
        } while (x /= 7);
        return (num >= 0 ? "" : "-") + res;
    }
};
