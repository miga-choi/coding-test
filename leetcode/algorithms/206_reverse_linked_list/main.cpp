#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ReverseLinkedList {
public:
    /**
     * Iteration
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        vector<ListNode*> stack;
        int top = -1;

        while (head != nullptr) {
            top++;
            stack.push_back(head);
            head = head->next;
        }

        ListNode* new_head = stack[top--];
        ListNode* curr_head = new_head;

        while (top >= 0) {
            curr_head->next = stack[top--];
            curr_head = curr_head->next;
        }

        curr_head->next = nullptr;

        return new_head;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Iteration
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    ListNode* solution1(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* next_temp = current->next;
            current->next = prev;
            prev = current;
            current = next_temp;
        }

        return prev;
    }

    /**
     * Solution 2
     * 
     * Recursion
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    ListNode* solution2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
