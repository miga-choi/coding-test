class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class RemovrlinkedListElements {
  /**
   * Dummy Node
   *
   * Complexities:
   *   N - Number of nodes in `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
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
  /**
   * Dummy Node
   *
   * Complexities:
   *   N - Number of nodes in `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  ListNode? solution(ListNode? head, int val) {
    ListNode dummy = ListNode(0, head);
    ListNode current = dummy;

    while (current.next != null) {
      ListNode nextNode = current.next!;

      if (nextNode.val == val) {
        current.next = nextNode.next;
      } else {
        current = nextNode;
      }
    }

    return dummy.next;
  }
}
