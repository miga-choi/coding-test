class RemoveDuplicatesFromSortedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

public:
    /**
     * Iteration
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr_head = head;

        while (curr_head) {
            if (curr_head->next && curr_head->val == curr_head->next->val) {
                curr_head->next = curr_head->next->next;
            } else {
                curr_head = curr_head->next;
            }
        }

        return head;
    }


    // Solution
    /**
     * Iteration
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    ListNode* solution(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* current = head;

        while (current && current->next) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
