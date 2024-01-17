class MergeTwoSortedLists {

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

  public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
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


  // Best Solution
  // Best Solution 1: recursion
  public ListNode bestSolution1(ListNode l1, ListNode l2) {
    if (l1 == null) {
      return l2;
    }
    if (l2 == null) {
      return l1;
    }
    if (l1.val < l2.val) {
      l1.next = mergeTwoLists(l1.next, l2);
      return l1;
    } else {
      l2.next = mergeTwoLists(l1, l2.next);
      return l2;
    }
  }

  // Best Solution 2: iteration
  public ListNode bestSolution2(ListNode l1, ListNode l2) {
    ListNode head = new ListNode(0);
    ListNode handler = head;
    while (l1 != null && l2 != null) {
      if (l1.val <= l2.val) {
        handler.next = l1;
        l1 = l1.next;
      } else {
        handler.next = l2;
        l2 = l2.next;
      }
      handler = handler.next;
    }

    if (l1 != null) {
      handler.next = l1;
    } else if (l2 != null) {
      handler.next = l2;
    }

    return head.next;
  }
}
