class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class PalindromeLinkedList {
  /**
   * Complexities:
   *   N - The number of nodes in `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
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


  // Solution
  /**
   * Complexities:
   *   N - The number of nodes in `head`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  bool solution(ListNode? head) {
    if (head == null || head.next == null) {
      return true;
    }

    ListNode? slow = head;
    ListNode? fast = head;
    while (fast != null && fast.next != null) {
      slow = slow?.next;
      fast = fast.next?.next;
    }

    ListNode? secondHalfHead = _reverse(slow);

    ListNode? p1 = head;
    ListNode? p2 = secondHalfHead;
    bool isPalin = true;

    while (p2 != null) {
      if (p1!.val != p2.val) {
        isPalin = false;
        break;
      }
      p1 = p1.next;
      p2 = p2.next;
    }

    _reverse(secondHalfHead);

    return isPalin;
  }

  ListNode? _reverse(ListNode? head) {
    ListNode? prev = null;
    ListNode? curr = head;
    while (curr != null) {
      ListNode? nextNode = curr.next;
      curr.next = prev;
      prev = curr;
      curr = nextNode;
    }
    return prev;
  }
}
