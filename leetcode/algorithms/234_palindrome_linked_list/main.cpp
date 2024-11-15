struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class PalindromeLinkedList
{
public:
    bool isPalindrome(ListNode *head)
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
    bool bestSolution(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev;
        ListNode *temp;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        prev = slow;
        slow = slow->next;
        prev->next = NULL;

        while (slow)
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        fast = head;
        slow = prev;

        while (slow)
        {
            if (fast->val != slow->val)
            {
                return false;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return true;
    }
};
