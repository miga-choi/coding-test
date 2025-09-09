struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MergeTwoSortedLists {
public:
    /**
     * Iteration
     * - Time Complexity: O(N + M)
     * - Space Complexity: O(1)
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        dummy.next = nullptr;
        ListNode* curr_head = &dummy;

        while (list1 || list2) {
            if (list1 && list2) {
                if (list1->val > list2->val) {
                    curr_head->next = list2;
                    list2 = list2->next;
                } else {
                    curr_head->next = list1;
                    list1 = list1->next;
                }
            } else if (list1) {
                curr_head->next = list1;
                list1 = list1->next;
            } else {
                curr_head->next = list2;
                list2 = list2->next;
            }
            curr_head = curr_head->next;
        }

        return dummy.next;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Iteration
     * - Time Complexity: O(N + M)
     * - Space Complexity: O(1)
     */
    ListNode* solution1(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* curr = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        curr->next = list1 ? list1 : list2;

        return dummy.next;
    }

    /**
     * Solution 2
     * 
     * Recursion
     * - Time Complexity: O(N + M)
     * - Space Complexity: O(N + M)
     */
    ListNode* solution2(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }

        if (list1->val <= list2->val) {
            list1->next = solution2(list1->next, list2);
            return list1;
        } else {
            list2->next = solution2(list1, list2->next);
            return list2;
        }
    }
};
