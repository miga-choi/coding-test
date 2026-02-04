#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Iteration
 * 
 * Complexities:
 *   N - Size of `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr_head = head;

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
struct ListNode* solution1(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            struct ListNode* temp = current->next;
            
            current->next = current->next->next;
            
            free(temp);
        } else {
            current = current->next;
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
struct ListNode* solution2(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    head->next = solution2(head->next);

    return head->val == head->next->val ? head->next : head;
}