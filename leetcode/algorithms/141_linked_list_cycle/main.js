function ListNode(val) {
  this.val = val;
  this.next = null;
}

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function (head) {
  const stack = [];
  while (head) {
    if (stack.indexOf(head) > -1) {
      return true;
    }
    stack.push(head);
    head = head.next;
  }
  return false;
};


// Solution
const solution = (head) => {
  let fast = head;
  while (fast && fast.next) {
    head = head.next;
    fast = fast.next.next;
    if (head === fast) {
      return true;
    }
  }
  return false;
};
