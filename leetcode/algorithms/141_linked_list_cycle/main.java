import java.util.ArrayList;
import java.util.List;

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

class LinkedListCycle {

  public class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
      val = x;
      next = null;
    }
  }

  public boolean hasCycle(ListNode head) {
    List<ListNode> stack = new ArrayList<ListNode>();
    while (head != null) {
      if (stack.indexOf(head) > -1) {
        return true;
      }
      stack.add(head);
      head = head.next;
    }
    return false;
  }

  // Best Solution
  public boolean bestSolution(ListNode head) {
    ListNode slow = head, fast = head;
    while (fast != null && fast.next != null) {
      fast = fast.next.next;
      slow = slow.next;
      if (fast == slow) return true;
    }
    return false;
  }
}
