#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
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
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
struct ListNode* solution(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }

    return head;
}
