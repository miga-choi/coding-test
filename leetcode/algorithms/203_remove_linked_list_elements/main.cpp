#include <stdlib.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class RemoveLinkedListElements
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *result = (ListNode *)malloc(sizeof(ListNode));
        result->next = head;
        ListNode *current = head;

        while (head->next)
        {
            if (head->next->val == val)
            {
                head->next = head->next->next;
            }
            else
            {

                head = head->next;
            }
        }

        return result->next;
    }

    // Best Solution 1: Solving the problem using two pointers.
    ListNode *bestSolution1(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }

        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }

    // Best Solution 2: Solving the problem using a single pointer.
    ListNode *bestSolution2(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }

        // This is for the case when a linked list is like this:
        // 1->1->2->null , val = 1
        // 1->1->1->null , val = 1
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }

        ListNode *curr = head;
        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                curr->next = curr->next->next;
                // After doing the above step, I am not updating "curr" because of these type of test cases:
                // 1->2->3->6->6->6->5->null  val = 6
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
};