struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *temp = 0;
    struct ListNode *result = 0;

    while (head)
    {
        temp = head->next;
        head->next = result;
        result = head;
        head = temp;
    }

    return result;
}

// Best Solution
struct ListNode *bestSolution(struct ListNode *head)
{
    struct ListNode *nextNode = 0;
    struct ListNode *prevNode = 0;
    while (head)
    {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    return prevNode;
}