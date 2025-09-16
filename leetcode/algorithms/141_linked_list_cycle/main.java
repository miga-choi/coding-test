class LinkedListCycle {
  /**
   * Floyd's Tortoise and Hare Algorithm
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
      val = x;
      next = null;
    }
  }

  public boolean hasCycle(ListNode head) {
    ListNode ahead = head;
    ListNode behind = head;

    while (ahead != null && ahead.next != null) {
      ahead = ahead.next.next;
      behind = behind.next;
      if (ahead == behind) {
        return true;
      }
    }

    return false;
  }


  // Solution
  /**
   * Floyd's Tortoise and Hare Algorithm
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  public boolean solution(ListNode head) {
    if (head == null || head.next == null) {
      return false;
    }

    ListNode slow = head;
    ListNode fast = head;

    while (fast != null && fast.next != null) {
      slow = slow.next;
      fast = fast.next.next;

      if (slow == fast) {
        return true;
      }
    }

    return false;
  }
}
