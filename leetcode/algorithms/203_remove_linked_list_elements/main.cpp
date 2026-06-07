#include <stdlib.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class RemoveLinkedListElements {
public:
    /**
     * Dummy Node
     *
     * Complexities:
     *   N - Number of nodes in `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* result = (ListNode*)malloc(sizeof(ListNode));
        result->next = head;
        ListNode* current = head;

        while (head->next) {
            if (head->next->val == val) {
                head->next = head->next->next;
            } else {
                head = head->next;
            }
        }

        return result->next;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Dummy Node
     *
     * Complexities:
     *   N - Number of nodes in `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    ListNode* solution1(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                
                curr->next = curr->next->next;
                
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return dummy.next;
    }

    /**
     * Solution 2
     * 
     * Recursion
     *
     * Complexities:
     *   N - Number of nodes in `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    ListNode* solution2(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }

        head->next = solution2(head->next, val);

        if (head->val == val) {
            ListNode* nextNode = head->next;
            delete head;
            return nextNode;
        }

        return head;
    }
};
