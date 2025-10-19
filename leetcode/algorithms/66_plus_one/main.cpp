#include <vector>
using namespace std;

class PlusOne {
public:
    /**
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

        int up = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += up;
            up = 0;

            if (digits[i] > 9) {
                digits[i] -= 10;
                up = 1;
            }
            result.insert(result.begin(), digits[i]);
        }

        if (up > 0) {
            result.insert(result.begin(), 1);
        }

        return result;
    }


    // Solution
    /**
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    vector<int> solution1(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            digits[i]++;
            
            if (digits[i] < 10) {
                return digits;
            }
            
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
