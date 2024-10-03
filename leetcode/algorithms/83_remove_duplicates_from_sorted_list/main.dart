class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class RemoveDuplicatesFromSortedList {
  ListNode? deleteDuplicates(ListNode? head) {
    ListNode? current = head;

    while (current != null) {
      if (current.next != null && current.next!.val == current.val) {
        current.next = current.next?.next;
      } else {
        current = current.next;
      }
    }

    return head;
  }

  // BestSolution
  ListNode? bestSolution(ListNode? head) {
    ListNode? value = head;

    while (value != null && value.next != null) {
      if (value.val == value.next?.val) {
        // If the current value is the same as the next one,
        // skip the next node
        value.next = value.next?.next;
      } else {
        // Otherwise, just move to the next node
        value = value.next;
      }
    }

    return head;
  }
}
