#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Floyd's Tortoise and Hare Algorithm
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
bool hasCycle(struct ListNode* head) {
    struct ListNode* ahead = head;
    struct ListNode* behind = head;

    while (ahead && ahead->next) {
        ahead = ahead->next->next;
        behind = behind->next;
        if (ahead == behind) {
            return true;
        }
    }

    return false;
}


// Solution
/**
 * Floyd's Tortoise and Hare Algorithm
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
bool solution(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}
