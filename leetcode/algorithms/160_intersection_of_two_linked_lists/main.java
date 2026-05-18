class IntersectionOfTwoLinkedLists {
  public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
      val = x;
      next = null;
    }
  }

  /**
   * Two-Pointer
   *
   * Complexities:
   *   N - Number of Nodes in `headA`
   *   M - Number of Nodes in `headB`
   *   - Time Complexity: O(M + N)
   *   - Space Complexity: O(1)
   */
  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    if (headA == null || headB == null) {
      return null;
    }

    ListNode ptrA = headA;
    ListNode ptrB = headB;

    while (ptrA != ptrB) {
      ptrA = (ptrA == null) ? headB : ptrA.next;
      ptrB = (ptrB == null) ? headA : ptrB.next;
    }

    return ptrA;
  }


  // Solution
  /**
   * Two-Pointer
   *
   * Complexities:
   *   N - Number of Nodes in `headA`
   *   M - Number of Nodes in `headB`
   *   - Time Complexity: O(M + N)
   *   - Space Complexity: O(1)
   */
  public ListNode solution(ListNode headA, ListNode headB) {
    if (headA == null || headB == null) {
      return null;
    }

    ListNode ptrA = headA;
    ListNode ptrB = headB;

    while (ptrA != ptrB) {
      ptrA = (ptrA == null) ? headB : ptrA.next;
      ptrB = (ptrB == null) ? headA : ptrB.next;
    }

    return ptrA;
  }
}
