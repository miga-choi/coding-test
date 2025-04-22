#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->next = head;
    struct ListNode* current = result;

    while (current->next) {
        if (current->next->val == val) {
            current->next = current->next->next;
            continue;
        }
        current = current->next;
    }

    return result->next;
}


// Solution
struct ListNode* solution(struct ListNode* head, int val) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = head;
    struct ListNode* curr = temp;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    
    return temp->next;
}
