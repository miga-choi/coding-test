function ListNode(val) {
  this.val = val;
  this.next = null;
}

/**
 * - Time Complexity: O(M * N)
 * - Space Complexity: O(1)
 *
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function (headA, headB) {
  while (headA) {
    let dummyB = headB;

    while (dummyB) {
      if (headA === dummyB) {
        return headA;
      }
      dummyB = dummyB.next;
    }

    headA = headA.next;
  }

  return headA;
};


// Solution
/**
 * Two-Pointer
 * - Time Complexity: O(M + N)
 * - Space Complexity: O(1)
 *
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var solution = function (headA, headB) {
  let pA = headA;
  let pB = headB;

  while (pA !== pB) {
    pA = pA === null ? headB : pA.next;
    pB = pB === null ? headA : pB.next;
  }

  return pA;
};
