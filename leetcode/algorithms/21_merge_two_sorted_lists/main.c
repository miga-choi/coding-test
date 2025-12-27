#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Iteration
 * 
 * Complexities:
 *   N - Length of `list1`
 *   M - Length of `list2`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* curr_head = &dummy;

    while (list1 && list2) {
        if (list1->val > list2->val) {
            curr_head->next = list2;
            list2 = list2->next;
        } else {
            curr_head->next = list1;
            list1 = list1->next;
        }
        curr_head = curr_head->next;
    }

    curr_head->next = list1 ? list1 : list2;

    return dummy.next;
}


// Solution
/**
 * Iterative Method with Dummy Node
 * 
 * Complexities:
 *   N - Length of `list1`
 *   M - Length of `list2`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
struct ListNode* solution(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* tail = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}
