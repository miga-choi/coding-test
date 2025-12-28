class MergeTwoSortedLists {
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

  /**
   * Iterative + Dummy Node
   *
   * Complexities:
   *   N - Length of `list1`
   *   M - Length of `list2`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(1)
   */
  public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
    ListNode dummy = new ListNode();
    ListNode currHead = dummy;

    while (list1 != null && list2 != null) {
      if (list1.val > list2.val) {
        currHead.next = list2;
        list2 = list2.next;
      } else {
        currHead.next = list1;
        list1 = list1.next;
      }
      currHead = currHead.next;
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
  public ListNode solution1(ListNode list1, ListNode list2) {
    ListNode dummy = new ListNode(-1);
    ListNode curr = dummy;

    while (list1 != null && list2 != null) {
      if (list1.val <= list2.val) {
        curr.next = list1;
        list1 = list1.next;
      } else {
        curr.next = list2;
        list2 = list2.next;
      }
      curr = curr.next;
    }

    if (list1 != null) {
      curr.next = list1;
    } else if (list2 != null) {
      curr.next = list2;
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
  public ListNode solution2(ListNode list1, ListNode list2) {
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
