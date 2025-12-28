#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Iterative + Dummy Node
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
 * Solution 1
 * 
 * Iterative + Dummy Node
 * 
 * Complexities:
 *   N - Length of `list1`
 *   M - Length of `list2`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
struct ListNode* solution1(struct ListNode* list1, struct ListNode* list2) {
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

/**
 * Solution 2
 * 
 * Recursive
 * 
 * Complexities:
 *   N - Length of `list1`
 *   M - Length of `list2`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(N + M)
 */
struct ListNode* solution2(struct ListNode* list1, struct ListNode* list2) {
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
