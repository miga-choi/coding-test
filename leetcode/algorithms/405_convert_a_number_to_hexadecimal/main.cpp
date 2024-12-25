#include <string>
using namespace std;

class ConvertANumberToHexadecimal {
public:
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

    // Best Solution
    string bestSolution(int num) {
        string HEX = "0123456789abcdef";

        if (num == 0) {
            return "0";
        }

        string result;
        int count = 0;

        while (num && count++ < 8) {
            result = HEX[(num & 0xf)] + result;
            num >>= 4;
        }

        return result;
    }
};
