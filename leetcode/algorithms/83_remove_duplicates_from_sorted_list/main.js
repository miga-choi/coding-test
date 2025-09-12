function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function (head) {
  let currHead = head;

  while (currHead) {
    if (currHead.next && currHead.val === currHead.next.val) {
      currHead.next = currHead.next.next;
    } else {
      currHead = currHead.next;
    }
  }

  return head;
};


// Solution
/**
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {ListNode} head
 * @return {ListNode}
 */
var solution = function (head) {
  if (head === null || head.next === null) {
    return head;
  }

  let current = head;

  while (current !== null && current.next !== null) {
    if (current.val === current.next.val) {
      current.next = current.next.next;
    } else {
      current = current.next;
    }
  }

  return head;
};
