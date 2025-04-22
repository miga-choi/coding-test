public class RemoveDuplicatesFromSortedList {
    public class ListNode {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode DeleteDuplicates(ListNode head) {
        ListNode current = head;
        while (current != null) {
            if (current.next != null && current.next.val == current.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return head;
    }


    // Solution
    // Solution 1
    public ListNode solution1(ListNode head) {
        ListNode n = head;

        while (n is not null) {
            while (n.val == n.next?.val) {
                n.next = n.next.next;
            }
            n = n.next;
        }

        return head;
    }

    // Solution 2
    public ListNode solution2(ListNode head) {
        if (head == null) {
            return null;
        }

        if (head.next == null) {
            return head;
        }

        ListNode prevNode = head;
        for (ListNode node = head.next; node != null; node = node.next) {
            if (node.val == prevNode.val) {
                prevNode.next = node.next;
            } else {
                prevNode = node;
            }
        }

        return head;
    }

    // Solution 3
    public ListNode solution3(ListNode head) {
        if (head == null) {
            // Don't forget this edge case
            return null;
        }

        // Helps for returning at the end
        ListNode ptr = head;

        // Terminates if there is no next node(end of list)
        while (ptr.next != null) {
            if (ptr.next.val == ptr.val) {
                // Check for duplicate next node
                // Delete next node
                ptr.next = ptr.next.next; 
            } else {
                // Advance if no duplicate is found
                ptr = ptr.next;
            }
        }

        // Return the original start of list
        return head;
    }
}
