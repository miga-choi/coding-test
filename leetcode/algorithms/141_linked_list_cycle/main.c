#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    struct ListNode *node1 = head;
    struct ListNode *node2 = head;

    while (node2 != 0 && node2->next != 0)
    {
        node1 = node1->next;
        node2 = node2->next->next;
        if (node1 == node2)
        {
            return true;
        }
    }

    return false;
}

// Best Solution
bool bestSolution(struct ListNode *head)
{
    // Initialize two node slow and fast point to the hesd node...
    struct ListNode *fastptr = head;
    struct ListNode *slowptr = head;
    while (fastptr != NULL && fastptr->next != NULL)
    {
        // Move slow pointer by 1 node and fast at 2 at each step.
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        // If both the pointers meet at any point, then the cycle is present and return true...
        if (slowptr == fastptr)
            return true;
    }
    return false;
}
