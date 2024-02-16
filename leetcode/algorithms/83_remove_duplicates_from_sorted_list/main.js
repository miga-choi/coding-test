function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function (head) {
  let result = head;
  while (result) {
    if (result.next && result.val === result.next.val) {
      result.next = result.next.next;
      continue;
    }
    result = result.next;
  }
  return head;
};


// Best Solution
// Best Solution 1:
var bestSolution1 = function (head) {
  var current = head;

  while (current) {
    if (current.next !== null && current.val == current.next.val) {
      current.next = current.next.next;
    } else {
      current = current.next;
    }
  }

  return head;
};

// Best Solution 2:
var bestSolution2 = function (head) {
  // Special case...
  if (head == null || head.next == null) {
    return head;
  }
  // Initialize a pointer curr with the address of head node...
  let curr = head;
  // Traverse all element through a while loop if curr node and the next node of curr node are present...
  while (curr != null && curr.next != null) {
    // If the value of curr is equal to the value of prev...
    // It means the value is present in the linked list...
    if (curr.val == curr.next.val) {
      // Hence we do not need to include curr again in the linked list...
      // So we increment the value of curr...
      curr.next = curr.next.next;
    }
    // Otherwise, we increment the curr pointer...
    else {
      curr = curr.next;
    }
  }
  return head; // Return the sorted linked list without any duplicate element...
};
