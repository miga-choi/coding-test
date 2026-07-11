function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * Complexities:
 *   N - The number of nodes in `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
  const obverse = [];
  const reverse = [];
  let newHead = head;

  while (newHead) {
    obverse.push(newHead.val);
    newHead = newHead.next;
  }

  let prev = null;
  let current = head;

  while (current) {
    const next = current.next;
    current.next = prev;
    prev = current;
    current = next;
  }

  while (prev) {
    reverse.push(prev.val);
    prev = prev.next;
  }

  for (let i = 0; i < obverse.length; i++) {
    if (obverse[i] !== reverse[i]) {
      return false;
    }
  }

  return true;
};


// Solution
/**
 * Complexities:
 *   N - The number of nodes in `head`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var solution = function (head) {
  if (!head || !head.next) {
    return true;
  }

  let slow = head;
  let fast = head;

  while (fast !== null && fast.next !== null) {
    slow = slow.next;
    fast = fast.next.next;
  }

  let prev = null;
  let curr = slow;

  while (curr !== null) {
    const nextTemp = curr.next;
    curr.next = prev;
    prev = curr;
    curr = nextTemp;
  }

  let p1 = head;
  let p2 = prev;

  while (p2 !== null) {
    if (p1.val !== p2.val) {
      return false;
    }
    p1 = p1.next;
    p2 = p2.next;
  }

  return true;
};
