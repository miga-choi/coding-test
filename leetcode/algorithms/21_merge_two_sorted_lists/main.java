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
   * Iteration
   * - Time Complexity: O(N + M)
   * - Space Complexity: O(1)
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
   * Iteration
   * - Time Complexity: O(N + M)
   * - Space Complexity: O(1)
   */
  public ListNode solution1(ListNode list1, ListNode list2) {
    ListNode dummy = new ListNode(-1);
    ListNode current = dummy;

    while (list1 != null && list2 != null) {
      if (list1.val <= list2.val) {
        current.next = list1;
        list1 = list1.next;
      } else {
        current.next = list2;
        list2 = list2.next;
      }
      current = current.next;
    }

    if (list1 != null) {
      current.next = list1;
    } else {
      current.next = list2;
    }

    return dummy.next;
  }

  /**
   * Solution 2
   * 
   * Recursion
   * - Time Complexity: O(N + M)
   * - Space Complexity: O(N + M)
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
