struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * - Time Complexity: O(M * N)
 * - Space Complexity: O(1)
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    while (headA) {
        struct ListNode* dummyB = headB;

        while (dummyB) {
            if (headA == dummyB) {
                return headA;
            }
            dummyB = dummyB->next;
        }

        headA = headA->next;
    }

    return headA;
}


// Solution
/**
 * Two-Pointer
 * - Time Complexity: O(M + N)
 * - Space Complexity: O(1)
 */
struct ListNode* solution(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    while (ptrA != ptrB) {
        ptrA = ptrA ? ptrA->next: headB;
        ptrB = ptrB ? ptrB->next: headA;
    }

    return ptrA;
}
