class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class AddTwoNumbers {
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
  ListNode? solution(ListNode? l1, ListNode? l2) {
    if (l1 == null && l2 == null) {
      return null;
    }

    int value = (l1?.val ?? 0) + (l2?.val ?? 0);
    int remainder = value ~/ 10;
    value %= 10;

    final remainNode = l1?.next ?? l2?.next;
    final node = new ListNode(value);

    if (remainNode == null) {
      if (remainder != 0) {
        node.next = ListNode(remainder);
      }
    } else {
      remainNode.val += remainder;
      node.next = addTwoNumbers(l1?.next, l2?.next);
    }

    return node;
  }
}
