function ListNode(val) {
  this.val = val;
  this.next = null;
}

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function (headA, headB) {
  let a = headA;
  while (a) {
    let b = headB;
    while (b) {
      if (a === b) {
        return a;
      }
      b = b.next;
    }
    a = a.next;
  }
  return null;
};


// Solution
// Idea:
// The naive approach here would be to store each node reference in a data structure until we saw the same one twice,
// but that would take O(N) extra space.
// In order to solve this problem with only O(1) extra space,
// we'll need to find another way to align the two linked lists.
// More importantly, we need to find a way to line up the ends of the two lists.
// And the easiest way to do that is to concatenate them in opposite orders, A+B and B+A.
// This way, the ends of the two original lists will align on the second half of each merged list.
// https://i.imgur.com/hcpocCV.png
// https://i.imgur.com/dDUjSPk.png
// Then we just need to check if at some point the two merged lists are pointing to the same node.
// In fact, even if the two merged lists don't intersect,
// the value of a and b will be the same (null) when we come to the end of the merged lists,
// so we can use that as our exit condition.
// We just need to make sure to string headB onto a and vice versa if one (but not both) list ends.
/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var solution = function (headA, headB) {
  let a = headA, b = headB;
  while (a !== b) {
    a = !a ? headB : a.next;
    b = !b ? headA : b.next;
  }
  return a;
};
