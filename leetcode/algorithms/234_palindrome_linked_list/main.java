import java.util.ArrayList;
import java.util.List;

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

    public boolean isPalindrome(ListNode head) {
        ListNode newHead = head;
        List<Integer> obverse = new ArrayList<Integer>();
        List<Integer> reverse = new ArrayList<Integer>();

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
            if (obverse.get(i) != reverse.get(i)) {
                return false;
            }
        }

        return true;
    }


    // Solution
    public boolean solution(ListNode head) {
        ListNode slow = head, fast = head, prev, temp;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        prev = slow;
        slow = slow.next;
        prev.next = null;

        while (slow != null) {
            temp = slow.next;
            slow.next = prev;
            prev = slow;
            slow = temp;
        }

        fast = head;
        slow = prev;

        while (slow != null) {
            if (fast.val != slow.val)
                return false;
            fast = fast.next;
            slow = slow.next;
        }

        return true;
    }
}
