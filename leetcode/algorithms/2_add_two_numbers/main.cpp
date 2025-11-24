struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class AddTwoNumbers {
public:
    /**
     * Complexities:
     *   M - l1 length
     *   N - l2 length
     *   - Time Complexity: O(Max(M, N))
     *   - Space Complexity: O(Max(M, N))
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* result = new ListNode();
        ListNode* head = result;

        while (l1 || l2 || carry) {
            int sum = carry;
            carry = 0;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (sum > 9) {
                sum -= 10;
                carry = 1;
            }

            ListNode* node = new ListNode(sum);
            head->next = node;
            head = head->next;
        }

        return result->next;
    }


    // Solution
    /**
     * Complexities:
     *   M - l1 length
     *   N - l2 length
     *   - Time Complexity: O(Max(M, N))
     *   - Space Complexity: O(Max(M, N))
     */
    ListNode* solution(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        return dummy.next;
    }
};
