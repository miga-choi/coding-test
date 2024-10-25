#include <string>
using namespace std;

class ExcelSheetColumnNumber
{
public:
    int titleToNumber(string columnTitle)
    {
        int length = columnTitle.size();
        int result = 0;
        for (int i = 0; i < length; i++)
        {
            result += ((int)columnTitle[length - i - 1] - 64) * pow(26, i);
        }
        return result;
    }

    // Best Solution
    int bestSolution(string columnTitle)
    {
        int result = 0;
        for (char c : columnTitle)
        {
            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};