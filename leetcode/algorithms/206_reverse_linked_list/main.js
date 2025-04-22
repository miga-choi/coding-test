function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
  let prev = null;
  let current = head;

  while (current) {
    const next = current.next;
    current.next = prev;
    prev = current;
    current = next;
  }

  return prev;
};


// Solution
// Solution 1: Recursive
var solution1 = function (head) {
  // Special case...
  if (head == null || head.next == null) {
    return head;
  }

  // Create a new node to call the function recursively and we get the reverse linked list...
  var res = solution1(head.next);

  // Set head node as head.next.next...
  head.next.next = head;

  //set head's next to be null...
  head.next = null;

  // Return the reverse linked list...
  return res;
};

// Solution 2: Iterative
var solution2 = function (head) {
  let prev = null;
  let curr = head;
  let next = null;

  while (curr !== null) {
    // save next
    next = curr.next;

    // reverse
    curr.next = prev;

    // advance prev and curr
    prev = curr;
    curr = next;
  }
  return prev;
};

// Solution 3: ES6 code
var solution3 = function (head) {
  let [prev, current] = [null, head];
  while (current) {
    [current.next, prev, current] = [prev, current, current.next];
  }
  return prev;
};
