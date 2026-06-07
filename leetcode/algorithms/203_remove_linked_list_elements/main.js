function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * Dummy Node
 *
 * Complexities:
 *   N - Number of nodes in `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function (head, val) {
  if (!head) {
    return null;
  }

  let currentHead = head;
  let nextHead = head.next;

  while (nextHead) {
    if (nextHead.val === val) {
      nextHead = nextHead.next;
      currentHead.next = nextHead;
    } else {
      currentHead = nextHead;
      nextHead = nextHead.next;
    }
  }

  if (head.val === val) {
    return head.next;
  }

  return head;
};


// Solution
/**
 * Dummy Node
 *
 * Complexities:
 *   N - Number of nodes in `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var solution = function (head, val) {
  const dummy = new ListNode(0, head);

  let current = dummy;

  while (current.next !== null) {
    if (current.next.val === val) {
      current.next = current.next.next;
    } else {
      current = current.next;
    }
  }

  return dummy.next;
};
