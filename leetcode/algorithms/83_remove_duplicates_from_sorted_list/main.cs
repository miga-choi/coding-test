public class RemoveDuplicatesFromSortedList
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode DeleteDuplicates(ListNode head)
    {
        ListNode current = head;
        while (current != null)
        {
            if (current.next != null && current.next.val == current.val)
            {
                current.next = current.next.next;
            }
            else
            {
                current = current.next;
            }
        }
        return head;
    }


    // Best Solution
    // Best Solution 1:
    public ListNode bestSolution1(ListNode head)
    {
        ListNode n = head;

        while (n is not null)
        {
            while (n.val == n.next?.val)
            {
                n.next = n.next.next;
            }
            n = n.next;
        }

        return head;
    }

    // Best Solution 2:
    public ListNode bestSolution2(ListNode head)
    {
        if (head == null)
        {
            return null;
        }

        if (head.next == null)
        {
            return head;
        }

        ListNode prevNode = head;
        for (ListNode node = head.next; node != null; node = node.next)
        {
            if (node.val == prevNode.val)
            {
                prevNode.next = node.next;
            }
            else
            {
                prevNode = node;
            }
        }

        return head;
    }

    // Best Solution 3:
    public ListNode bestSolution3(ListNode head)
    {
        if (head == null)
        {
            return null; // Don't forget this edge case
        }
        ListNode ptr = head; // Helps for returning at the end

        while (ptr.next != null)
        {
            // Terminates if there is no next node(end of list)
            if (ptr.next.val == ptr.val)
            {
                // Check for duplicate next node
                ptr.next = ptr.next.next; // Delete next node
            }
            else
            {
                ptr = ptr.next;  // Advance if no duplicate is found
            }
        }
        return head; //Return the original start of list
    }
}
