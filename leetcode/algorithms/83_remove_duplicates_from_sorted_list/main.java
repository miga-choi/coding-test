class RemoveDuplicatesFromSortedList {
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

  public ListNode deleteDuplicates(ListNode head) {
    ListNode result = head;
    while (result != null) {
      if (result.next != null && result.val == result.next.val) {
        result.next = result.next.next;
      } else {
        result = result.next;
      }
    }
    return head;
  }


  // Solution
  // Solution 1: Recursive
  public ListNode solution1(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }
    head.next = solution1(head.next);
    return head.val == head.next.val ? head.next : head;
  }

  // Solution 2
  public ListNode solution2(ListNode head) {
    ListNode list = head;

    while (list != null) {
      if (list.next == null) {
        break;
      }
      if (list.val == list.next.val) {
        list.next = list.next.next;
      } else {
        list = list.next;
      }
    }

    return head;
  }
}
