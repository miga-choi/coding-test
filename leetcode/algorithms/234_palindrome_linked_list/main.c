#include <stdbool.h>
#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *reverse = 0;
    struct ListNode *temp;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        temp = slow->next;
        slow->next = reverse;
        reverse = slow;
        slow = temp;
    }

    slow = (fast ? slow->next : slow);

    while (slow)
    {
        if (slow->val != reverse->val)
        {
            return false;
        }
        slow = slow->next;
        reverse = reverse->next;
    }

    return true;
}

// Best Solution
bool bestSolution(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;
    struct ListNode *tmp;

    // finding mid point
    while (fast && fast->next)
    {
        fast = fast->next->next;
        tmp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = tmp;
    }

    // for odd length case as mentioned above
    slow = (fast ? slow->next : slow);

    // check if linked lists starting at prev and slow are equal
    while (slow)
    {
        if (slow->val != prev->val)
        {
            return false;
        }
        else
        {
            slow = slow->next;
            prev = prev->next;
        }
    }
    return true;
}
