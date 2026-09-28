#include <algorithm> // std::reverse
#include <cstdint>   // std::uint32_t
#include <format>    // std::format
#include <string>    // std::string
using namespace std;

class ConvertANumberToHexadecimal {
public:
    /**
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    string toHex(int num) {
        unsigned int unum = num;
        string hex = "0123456789abcdef";
        string result = "";

        while (1) {
            result = hex.at(unum % 16) + result;
            unum >>= 4;
            if (!unum) {
                break;
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    string solution1(int num) {
        if (num == 0) {
            return "0";
        }

        static constexpr char DIGITS[] = "0123456789abcdef";
        auto u = static_cast<uint32_t>(num);

        string res;
        while (u != 0) {
            res.push_back(DIGITS[u & 0xF]);
            u >>= 4;
        }

        reverse(res.begin(), res.end());

        return res;
    }

    /**
     * Solution 2
     * 
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    string solution2(int num) {
        if (num == 0) {
            return "0";
        }

        static constexpr char DIGITS[] = "0123456789abcdef";
        auto u = static_cast<uint32_t>(num);

        string buf(8, '0');
        int pos = 8;
        while (u != 0) {
            buf[--pos] = DIGITS[u & 0xF];
            u >>= 4;
        }

        return buf.substr(pos);
    }

    /**
     * Solution 3
     * 
     * std::format (C++20)
     * 
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    string solution3(int num) {
        return format("{:x}", static_cast<uint32_t>(num));
    }
};
