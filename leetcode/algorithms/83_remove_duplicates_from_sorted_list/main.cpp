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
     * 
     * Complexities:
     *   N - Size of `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
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
     * Solution 1
     *
     * Iteration
     *
     * Complexities:
     *   N - Size of `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    ListNode* solution1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* temp = curr->next;
                
                curr->next = curr->next->next;
                
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }

    /**
     * Solution 2
     *
     * Recursion
     *
     * Complexities:
     *   N - Size of `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    ListNode* solution2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        head->next = solution2(head->next);

        return head->val == head->next->val ? head->next : head;
    }
};
