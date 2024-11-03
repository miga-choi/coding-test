class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class ReverseLinkedList {
  ListNode? reverseList(ListNode? head) {
    ListNode? temp = null;
    ListNode? result = null;

    while (head != null) {
      temp = head.next;
      head.next = result;
      result = head;
      head = temp;
    }

    return result;
  }

  // Best Solution
  ListNode? bestSolution(ListNode? head) {
    final tm = ListNode();
    while (head != null) {
      tm.next = ListNode(head.val, tm.next);
      head = head.next;
    }
    return tm.next;
  }
}
