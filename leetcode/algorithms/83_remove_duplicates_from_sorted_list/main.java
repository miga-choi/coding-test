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


  // Best Solution
  // Best Solution 1: Recursive
  public ListNode bestSolution1(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }
    head.next = bestSolution1(head.next);
    return head.val == head.next.val ? head.next : head;
  }

  // Best Solution 2:
  public ListNode bestSolution2(ListNode head) {
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
