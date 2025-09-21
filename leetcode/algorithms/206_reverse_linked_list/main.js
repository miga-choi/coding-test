function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
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
/*
 * Solution 1
 *
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 */
var solution1 = function (head) {
  let prev = null;
  let current = head;
  let nextTemp = null;

  while (current !== null) {
    nextTemp = current.next;
    current.next = prev;
    prev = current;
    current = nextTemp;
  }

  return prev;
};

/*
 * Solution 2
 *
 * Recursion
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */
var solution2 = function (head) {
  if (head === null || head.next === null) {
    return head;
  }

  const reversedListHead = solution2(head.next);

  head.next.next = head;
  head.next = null;

  return reversedListHead;
};
