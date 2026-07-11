struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class PalindromeLinkedList {
public:
    /**
     * Complexities:
     *   N - The number of nodes in `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    bool isPalindrome(ListNode* head) {
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }

    bool solution(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalfHead = reverseList(slow);

        ListNode* p1 = head;
        ListNode* p2 = secondHalfHead;
        bool isPalin = true;

        while (p2 != nullptr) {
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
};
