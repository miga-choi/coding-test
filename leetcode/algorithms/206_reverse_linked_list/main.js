function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * Iteration
 *
 * Complexities:
 *   N - Number of node in `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
  if (head === null || head.next === null) {
    return head;
  }

  const stack = new Array();

  while (head) {
    stack.push(head);
    head = head.next;
  }

  const newHead = stack.pop();
  let currHead = newHead;

  while (stack.length > 0) {
    currHead.next = stack.pop();
    currHead = currHead.next;
  }

  currHead.next = null;

  return newHead;
};


// Solution
/**
 * Solution 1
 *
 * Iteration
 *
 * Complexities:
 *   N - Number of node in `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var solution1 = function (head) {
  let prev = null;
  let curr = head;

  while (curr !== null) {
    const nextTemp = curr.next;

    curr.next = prev;

    prev = curr;
    curr = nextTemp;
  }

  return prev;
};

/**
 * Solution 2
 *
 * Recursion
 *
 * Complexities:
 *   N - Number of node in `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var solution2 = function (head) {
  if (head === null || head.next === null) {
    return head;
  }

  const reversedHead = solution2(head.next);

  head.next.next = head;

  head.next = null;

  return reversedHead;
};
