#include <unordered_set>
using namespace std;

class HappyNumber {
public:
    /**
     * Floyd's Cycle-Finding Algorithm
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    int sum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int fast = n;
        int slow = n;

        while (true) {
            slow = sum(slow);
            fast = sum(fast);
            fast = sum(fast);
            if (fast == 1) {
                break;
            }
            if (slow == fast) {
                return false;
            }
        }

        return true;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Floyd's Cycle-Finding Algorithm
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    int getNext1(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool solution1(int n) {
        int slow = n;
        int fast = getNext1(n);

        while (fast != 1 && slow != fast) {
            slow = getNext1(slow);
            fast = getNext1(getNext1(fast));
        }

        return fast == 1;
    }

    /**
     * Solution 2
     * 
     * unordered_set
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(logᴺ)
     */
    int getNext2(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool solution2(int n) {
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext2(n);
        }

        return n == 1;
    }
};
