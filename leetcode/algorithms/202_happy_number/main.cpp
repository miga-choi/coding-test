#include <unordered_set>
using namespace std;

class HappyNumber {
public:
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
    // Solution 1: Hash Table
    int nextNumber1(int n) {
        int newNumber = 0;
        while (n != 0) {
            int num = n % 10;
            newNumber += num * num;
            n = n / 10;
        }
        return newNumber;
    }

    bool solution1(int n) {
        unordered_set<int> set;
        while (n != 1 && !set.count(n)) {
            set.insert(n);
            n = nextNumber1(n);
        }
        return n == 1;
    }

    // Solution 2: Floyd's Cycle-Finding Algorithm
    int nextNumber2(int n) {
        int newNumber = 0;
        while (n != 0) {
            int num = n % 10;
            newNumber += num * num;
            n = n / 10;
        }
        return newNumber;
    }

    bool solution2(int n) {
        int slowPointer = n;
        int fastPointer = nextNumber2(n);
        while (fastPointer != 1 && fastPointer != slowPointer) {
            slowPointer = nextNumber2(slowPointer);
            fastPointer = nextNumber2(nextNumber2(fastPointer));
        }
        return fastPointer == 1;
    }
};
