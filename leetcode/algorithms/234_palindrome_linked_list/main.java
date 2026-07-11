import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

class PalindromeLinkedList {
    class ListNode {
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
     *   N - The number of nodes in `head`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public boolean isPalindrome(ListNode head) {
        ListNode newHead = head;
        List<Integer> obverse = new ArrayList<>();
        List<Integer> reverse = new ArrayList<>();

        while (newHead != null) {
            obverse.add(newHead.val);
            newHead = newHead.next;
        }

        ListNode prev = null;
        ListNode current = head;

        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        while (prev != null) {
            reverse.add(prev.val);
            prev = prev.next;
        }

        for (int i = 0; i < obverse.size(); i++) {
            if (!Objects.equals(obverse.get(i), reverse.get(i))) {
                return false;
            }
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
    public boolean solution(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }

        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode secondHalfHead = reverse(slow);

        ListNode p1 = head;
        ListNode p2 = secondHalfHead;
        boolean isPalindrome = true;

        while (p2 != null) {
            if (p1.val != p2.val) {
                isPalindrome = false;
                break;
            }
            p1 = p1.next;
            p2 = p2.next;
        }

        reverse(secondHalfHead);

        return isPalindrome;
    }

    private ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }
}
