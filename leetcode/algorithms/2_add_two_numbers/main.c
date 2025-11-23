#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Complexities:
 *   M - l1 length
 *   N - l2 length
 *   - Time Complexity: O(Max(M, N))
 *   - Space Complexity: O(Max(M, N))
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;

    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = result;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        int current_val = sum % 10;

        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = current_val;
        node->next = NULL;

        head->next = node;
        head = head->next;
    }

    return result->next;
}


// Solution
/**
 * Complexities:
 *   M - l1 length
 *   N - l2 length
 *   - Time Complexity: O(Max(M, N))
 *   - Space Complexity: O(Max(M, N))
 */
struct ListNode* solution(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* current = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;

        int sum = carry + x + y;
        carry = sum / 10;

        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;

        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }

    return dummy.next;
}
