#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListCycle {
public:
    /**
     * Floyd's Tortoise and Hare Algorithm
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    bool hasCycle(ListNode* head) {
        ListNode* ahead = head;
        ListNode* behind = head;

        while (ahead && ahead->next) {
            ahead = ahead->next->next;
            behind = behind->next;
            if (ahead == behind) {
                return true;
            }
        }

        return false;
    }


    // Solution
    /**
     * Floyd's Tortoise and Hare Algorithm
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    bool solution(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
