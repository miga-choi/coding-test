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
     *
     * Complexities:
     *   N - Number of node in `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
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
     *
     * Complexities:
     *   N - Number of node in `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    ListNode* solution1(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextTemp = nullptr;

        while (curr != nullptr) {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }

    /**
     * Solution 2
     *
     * Recursion
     *
     * Complexities:
     *   N - Number of node in `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    ListNode* solution2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* p = solution2(head->next);

        head->next->next = head;
        
        head->next = nullptr;

        return p;
    }
};
