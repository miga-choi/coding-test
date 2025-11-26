class AddTwoNumbers {
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    /**
     * Complexities:
     *   M - Length of `l1`
     *   N - Length of `l2`
     *   - Time Complexity: O(Max(M, N))
     *   - Space Complexity: O(Max(M, N))
     */
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;

        ListNode result = new ListNode();
        ListNode head = result;

        while (l1 != null || l2 != null || carry > 0) {
            int sum = carry;
            carry = 0;

            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }

            if (sum > 9) {
                sum -= 10;
                carry = 1;
            }

            head.next = new ListNode(sum);
            head = head.next;
        }

        return result.next;
    }


    // Solution
    /**
     * Complexities:
     *   M - Length of `l1`
     *   N - Length of `l2`
     *   - Time Complexity: O(Max(M, N))
     *   - Space Complexity: O(Max(M, N))
     */
    public ListNode solution(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode curr = dummyHead;

        int carry = 0;

        while (l1 != null || l2 != null || carry > 0) {
            int x = (l1 != null) ? l1.val : 0;
            int y = (l2 != null) ? l2.val : 0;

            int sum = carry + x + y;

            carry = sum / 10;

            curr.next = new ListNode(sum % 10);

            curr = curr.next;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }

        return dummyHead.next;
    }
}
