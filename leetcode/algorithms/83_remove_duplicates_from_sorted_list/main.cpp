#include <cstddef>

class Solution
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *current = head;

        while (current)
        {
            if (current->next && current->next->val == current->val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }

        return head;
    }


    // Best Solution
    // Best Solution 1:
    ListNode *bestSolution1(ListNode *head)
    {
        ListNode *cur = head;
        while (cur)
        {
            while (cur->next && cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }

    // Best Solution 2:
    ListNode *bestSolution2(ListNode *head)
    {
        ListNode *temp = head;
        while (temp && temp->next)
        {
            if (temp->next->val == temp->val)
            {
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }
        return head;
    }

    // Best Solution 3:
    ListNode *bestSolution3(ListNode *head)
    {
        // Special case...
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Initialize two pointers tmp(slow) and curr(fast)...
        ListNode *tmp = head;
        ListNode *curr = head->next;
        // Traverse all element through a while loop if curr node is not null...
        while (curr != NULL)
        {
            // If the value of curr is equal to the value of tmp...
            // It means the value is present in the linked list...
            if (tmp->val == curr->val)
            {
                // Hence we do not need to include curr again in the linked list...
                // So we increment the value of curr...
                curr = curr->next;
            }
            // Otherwise, we increment both the pointers.
            else
            {
                tmp->next = curr;
                tmp = curr;
                curr = tmp->next;
            }
        }
        tmp->next = NULL;
        return head; // Return the sorted linked list without any duplicate element...
    }
};
