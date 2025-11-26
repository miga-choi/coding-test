class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class AddTwoNumbers {
  /**
   * Complexities:
   *   M - Length of `l1`
   *   N - Length of `l2`
   *   - Time Complexity: O(Max(M, N))
   *   - Space Complexity: O(Max(M, N))
   */
  ListNode? addTwoNumbers(ListNode? l1, ListNode? l2) {
    int carry = 0;

    ListNode? result = ListNode();
    ListNode? head = result;

    while (l1 != null || l2 != null || carry > 0) {
      int sum = carry;
      carry = 0;

      if (l1 != null) {
        sum += l1.val;
        l1 = l1.next;
      }

      if (l2 != null) {
        sum += l2.val;
        l2 = l2.next;
      }

      if (sum > 9) {
        sum -= 10;
        carry = 1;
      }

      head?.next = ListNode(sum);
      head = head?.next;
    }

    return result.next;
  }


  // Solution
  /**
   * Complexities:
   *   M - Length of `l1`
   *   N - Length of `l2`
   *   - Time Complexity: O(Max(M, N))
   *   - Space Complexity: O(Max(M, N))
   */
  ListNode? solution(ListNode? l1, ListNode? l2) {
    ListNode dummyHead = ListNode(0);
    ListNode current = dummyHead;

    int carry = 0;

    while (l1 != null || l2 != null || carry > 0) {
      int x = (l1 != null) ? l1.val : 0;
      int y = (l2 != null) ? l2.val : 0;

      int sum = x + y + carry;

      carry = sum ~/ 10;

      current.next = ListNode(sum % 10);
      current = current.next!;

      if (l1 != null) {
        l1 = l1.next;
      }
      if (l2 != null) {
        l2 = l2.next;
      }
    }

    return dummyHead.next;
  }
}
