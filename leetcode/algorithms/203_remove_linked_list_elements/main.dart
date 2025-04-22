class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class RemovrlinkedListElements {
  ListNode? removeElements(ListNode? head, int val) {
    ListNode? result = ListNode();
    result.next = head;
    ListNode? current = result;

    while (current?.next != null) {
      if (current?.next?.val == val) {
        current?.next = current.next?.next;
      } else {
        current = current?.next;
      }
    }

    return result.next;
  }


  // Solution
  ListNode? solution(ListNode? head, int val) {
    if (head == null) {
      return null;
    }
    if (head.next != null) {
      head.next = removeElements(head.next, val);
    }
    if (head.val == val) {
      head = head.next;
    }
    return head;
  }
}
