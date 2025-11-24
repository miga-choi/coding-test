function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * Complexities:
 *   M - l1 length
 *   N - l2 length
 *   - Time Complexity: O(Max(M, N))
 *   - Space Complexity: O(Max(M, N))
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
  let sum = 0;
  let carry = 0;

  const result = new ListNode(0);
  let head = result;

  while (l1 || l2 || sum > 0) {
    if (l1) {
      sum += l1.val;
      l1 = l1.next;
    }
    if (l2) {
      sum += l2.val;
      l2 = l2.next;
    }

    if (sum >= 10) {
      carry = 1;
      sum -= 10;
    }

    head.next = new ListNode(sum);
    head = head.next;

    sum = carry;
    carry = 0;
  }

  return result.next;
};


// Solution
/**
 * Complexities:
 *   M - l1 length
 *   N - l2 length
 *   - Time Complexity: O(Max(M, N))
 *   - Space Complexity: O(Max(M, N))
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var solution = function (l1, l2) {
  let dummyHead = new ListNode(0);
  let current = dummyHead;
  let carry = 0;

  while (l1 !== null || l2 !== null || carry > 0) {
    const val1 = l1 !== null ? l1.val : 0;
    const val2 = l2 !== null ? l2.val : 0;

    const sum = val1 + val2 + carry;

    carry = Math.floor(sum / 10);

    const digit = sum % 10;

    current.next = new ListNode(digit);
    current = current.next;

    if (l1 !== null) {
      l1 = l1.next;
    }
    if (l2 !== null) {
      l2 = l2.next;
    }
  }

  return dummyHead.next;
};
