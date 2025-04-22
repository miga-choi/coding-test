#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;

    while (current) {
        if (current->next && current->next->val == current->val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }

    return head;
}


// Solution
// Solution 1
struct ListNode* solution1(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp && temp->next) {
        if (temp->next->val == temp->val) {
            temp->next = temp->next->next;
            continue;
        }
        temp = temp->next;
    }
    return head;
}

// Solution 2
struct ListNode* solution2(struct ListNode* head) {
    struct ListNode* cur = head;
    while (cur) {
        while (cur->next && cur->val == cur->next->val) {
            cur->next = cur->next->next;
        }
        cur = cur->next;
    }
    return head;
}

// Solution 3
struct ListNode* solution3(struct ListNode* head) {
    // Special case...
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Initialize two pointers tmp(slow) and curr(fast)...
    struct ListNode* tmp = head;
    struct ListNode* curr = head->next;

    // Traverse all element through a while loop if curr node is not null...
    while (curr != NULL) {
        // If the value of curr is equal to the value of tmp...
        // It means the value is present in the linked list...
        if (tmp->val == curr->val) {
            // Hence we do not need to include curr again in the linked list...
            // So we increment the value of curr...
            curr = curr->next;
        } else {
            // Otherwise, we increment both the pointers.
            tmp->next = curr;
            tmp = curr;
            curr = tmp->next;
        }
    }

    tmp->next = NULL;

    // Return the sorted linked list without any duplicate element...
    return head;
}
