struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    while (headA != 0) {
        struct ListNode* temp = headB;
        while (temp != 0) {
            if (temp == headA) {
                return temp;
            }
            temp = temp->next;
        }
        headA = headA->next;
    }
    return 0;
}

// Solution
struct ListNode* solution(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* a = headA, *b = headB;
    while (a != b) {
        a = !a ? headB : a->next;
        b = !b ? headA : b->next;
    }
    return a;
}
