class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class PalindromeLinkedList {
  bool isPalindrome(ListNode? head) {
    final List<int> intList = List<int>.empty(growable: true);

    while (head != null) {
      intList.add(head.val);
      head = head.next;
    }

    final List<int> reverseIntList = intList.reversed.toList();
    for (var i = 0; i < intList.length; i++) {
      if (intList[i] != reverseIntList[i]) {
        return false;
      }
    }

    return true;
  }

  // Best Solution
  bool bestSolution(ListNode? head) {
    final values = <int>[];
    while (head != null) {
      values.add(head.val);
      head = head.next;
    }
    return values.join('') == values.reversed.join('');
  }
}
