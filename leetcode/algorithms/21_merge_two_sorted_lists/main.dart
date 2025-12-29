class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class MergeTwoSortedLists {
  /**
   * Iterative + Dummy Node
   *
   * Complexities:
   *   N - Length of `list1`
   *   M - Length of `list2`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(1)
   */
  ListNode? mergeTwoLists(ListNode? list1, ListNode? list2) {
    ListNode dummy = ListNode();
    ListNode currHead = dummy;

    while (list1 != null && list2 != null) {
      if (list1.val > list2.val) {
        currHead.next = list2;
        list2 = list2.next;
      } else {
        currHead.next = list1;
        list1 = list1.next;
      }
      currHead = currHead.next!;
    }

    currHead.next = list1 == null ? list2 : list1;

    return dummy.next;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Iterative + Dummy Node
   *
   * Complexities:
   *   N - Length of `list1`
   *   M - Length of `list2`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(1)
   */
  ListNode? solution1(ListNode? list1, ListNode? list2) {
    ListNode dummy = ListNode(0);
    ListNode current = dummy;

    while (list1 != null && list2 != null) {
      if (list1.val <= list2.val) {
        current.next = list1;
        list1 = list1.next;
      } else {
        current.next = list2;
        list2 = list2.next;
      }
      current = current.next!;
    }

    if (list1 != null) {
      current.next = list1;
    } else if (list2 != null) {
      current.next = list2;
    }

    return dummy.next;
  }

  /**
   * Solution 2
   * 
   * Recursive
   *
   * Complexities:
   *   N - Length of `list1`
   *   M - Length of `list2`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(N + M)
   */
  ListNode? solution2(ListNode? list1, ListNode? list2) {
    if (list1 == null) {
      return list2;
    }
    if (list2 == null) {
      return list1;
    }

    if (list1.val <= list2.val) {
      list1.next = solution2(list1.next, list2);
      return list1;
    } else {
      list2.next = solution2(list1, list2.next);
      return list2;
    }
  }
}
