#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Two-Pointer
 * 
 * Complexities:
 *   N - Size of `headA`
 *   M - Size of `headB`
 *   - Time Complexity: O(M + N)
 *   - Space Complexity: O(1)
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    while (ptrA != ptrB) {
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }

    return ptrA;
}


// Solution
/**
 * Two-Pointer
 * 
 * Complexities:
 *   N - Size of `headA`
 *   M - Size of `headB`
 *   - Time Complexity: O(M + N)
 *   - Space Complexity: O(1)
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    while (ptrA != ptrB) {
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }

    return ptrA;
}
