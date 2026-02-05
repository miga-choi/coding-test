function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * Iteration
 *
 * Complexities:
 *   N - Size of `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
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
 * Solution 1
 *
 * Iteration
 *
 * Complexities:
 *   N - Size of `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var solution1 = function (head) {
  if (!head || !head.next) {
    return head;
  }

  let current = head;

  while (current && current.next) {
    if (current.val === current.next.val) {
      current.next = current.next.next;
    } else {
      current = current.next;
    }
  }

  return head;
};

/**
 * Solution 2
 *
 * Recursion
 *
 * Complexities:
 *   N - Size of `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var solution2 = function (head) {
  if (!head || !head.next) {
    return head;
  }

  head.next = solution2(head.next);

  return head.val == head.next.val ? head.next : head;
};
