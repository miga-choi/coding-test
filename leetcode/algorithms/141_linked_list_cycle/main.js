function ListNode(val) {
  this.val = val;
  this.next = null;
}

/**
 * Floyd's Tortoise and Hare Algorithm
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
  let ahead = head;
  let behind = head;

  while (ahead && ahead.next) {
    ahead = ahead.next.next;
    behind = behind.next;
    if (ahead == behind) {
      return true;
    }
  }

  return false;
};


// Solution
/**
 * Floyd's Tortoise and Hare Algorithm
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {ListNode} head
 * @return {boolean}
 */
var solution = function (head) {
  if (head === null || head.next === null) {
    return false;
  }

  let slow = head;
  let fast = head;

  while (fast !== null && fast.next !== null) {
    slow = slow.next;
    fast = fast.next.next;

    if (slow === fast) {
      return true;
    }
  }

  return false;
};
