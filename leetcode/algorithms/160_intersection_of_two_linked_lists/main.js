function ListNode(val) {
  this.val = val;
  this.next = null;
}

/**
 * Two-Pointer
 *
 * Complexities:
 *   N - Number of Nodes in `headA`
 *   M - Number of Nodes in `headB`
 *   - Time Complexity: O(M + N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function (headA, headB) {
  if (!headA || !headB) {
    return null;
  }

  let ptrA = headA;
  let ptrB = headB;

  while (ptrA !== ptrB) {
    ptrA = ptrA === null ? headB : ptrA.next;
    ptrB = ptrB === null ? headA : ptrB.next;
  }

  return ptrA;
};


// Solution
/**
 * Two-Pointer
 *
 * Complexities:
 *   N - Number of Nodes in `headA`
 *   M - Number of Nodes in `headB`
 *   - Time Complexity: O(M + N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var solution = function (headA, headB) {
  if (!headA || !headB) {
    return null;
  }

  let pA = headA;
  let pB = headB;

  while (pA !== pB) {
    pA = pA === null ? headB : pA.next;
    pB = pB === null ? headA : pB.next;
  }

  return pA;
};
