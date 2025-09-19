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
   * - Time Complexity: O(M * N)
   * - Space Complexity: O(1)
   */
  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    while (headA != null) {
      ListNode dummyB = headB;

      while (dummyB != null) {
        if (headA == dummyB) {
          return headA;
        }

        dummyB = dummyB.next;
      }

      headA = headA.next;
    }

    return headA;
  }

  // Solution
  /**
   * Two-Pointer
   * - Time Complexity: O(M + N)
   * - Space Complexity: O(1)
   */
  public ListNode solution(ListNode headA, ListNode headB) {
    ListNode ptrA = headA;
    ListNode ptrB = headB;

    while (ptrA != ptrB) {
      ptrA = (ptrA == null) ? headB : ptrA.next;
      ptrB = (ptrB == null) ? headA : ptrB.next;
    }

    return ptrA;
  }
}
