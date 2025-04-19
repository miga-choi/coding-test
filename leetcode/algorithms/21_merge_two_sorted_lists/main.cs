public class MergeTwoSortedLists {
    public class ListNode {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode result = new ListNode();
        ListNode currentNode = result;

        while (list1 != null || list2 != null) {
            if (list1 != null && list2 != null) {
                if (list1.val > list2.val) {
                    currentNode.next = list2;
                    list2 = list2.next;
                } else {
                    currentNode.next = list1;
                    list1 = list1.next;
                }
            } else if (list1 != null) {
                currentNode.next = list1;
                list1 = list1.next;
            } else {
                currentNode.next = list2;
                list2 = list2.next;
            }
            currentNode = currentNode.next;
        }

        return result.next;
    }


    // Solution
    // Solution 1: Recursive
    public ListNode solution1(ListNode list1, ListNode list2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        if (l1.val <= l2.val) {
            l1.next = MergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = MergeTwoLists(l1, l2.next);
            return l2;
        }
    }

    // Solution 2: Iterative
    public ListNode solution2(ListNode list1, ListNode list2) {
        var dummyNode = new ListNode();
        var tail = dummyNode;

        var pointer1 = list1;
        var pointer2 = list2;

        while (pointer1 != null && pointer2 != null) {
            if (pointer1.val < pointer2.val) {
                tail.next = pointer1;
                pointer1 = pointer1.next;
            } else {
                tail.next = pointer2;
                pointer2 = pointer2.next;
            }

            tail = tail.next;
        }

        tail.next = pointer1 ?? pointer2;

        return dummyNode.next;
    }
}
