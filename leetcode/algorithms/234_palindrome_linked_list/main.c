#include <stdbool.h>
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Complexities:
 *   N - The number of nodes in `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* reverse = 0;
    struct ListNode* temp;

    while (fast && fast->next) {
        fast = fast->next->next;
        temp = slow->next;
        slow->next = reverse;
        reverse = slow;
        slow = temp;
    }

    slow = (fast ? slow->next : slow);

    while (slow) {
        if (slow->val != reverse->val) {
            return false;
        }
        slow = slow->next;
        reverse = reverse->next;
    }

    return true;
}


// Solution
/**
 * Complexities:
 *   N - The number of nodes in `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    return prev;
}

bool solution(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* secondHalfHead = reverseList(slow);
    
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalfHead;
    bool isPalin = true;

    while (p2 != NULL) {
        if (p1->val != p2->val) {
            isPalin = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    reverseList(secondHalfHead);

    return isPalin;
}
