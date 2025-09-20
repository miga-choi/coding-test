#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */
struct ListNode* reverseList_iterative(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* stack[5000];
    int top = -1;

    struct ListNode* temp = head;
    while (temp != NULL) {
        stack[++top] = temp;
        temp = temp->next;
    }

    struct ListNode* new_head = stack[top];
    temp = new_head;
    top--;

    while (top >= 0) {
        struct ListNode* current_node = stack[top--];
        temp->next = current_node;
        temp = temp->next;
    }

    temp->next = NULL;

    return new_head;
}


// Solution
/**
 * Solution 1
 * 
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
struct ListNode* solution1(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next_temp = NULL;

    while (current != NULL) {
        next_temp = current->next;
        
        current->next = prev;
        
        prev = current;
        current = next_temp;
    }

    return prev;
}

/**
 * Solution 2
 * 
 * Recursion
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */
struct ListNode* solution2(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* newHead = solution2(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}
