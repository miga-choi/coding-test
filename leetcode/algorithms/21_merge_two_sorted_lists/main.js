function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

/**
 * Iteration
 * - Time Complexity: O(N + M)
 * - Space Complexity: O(1)
 *
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function (list1, list2) {
  const dummy = new ListNode();
  let curr_head = dummy;

  while (list1 && list2) {
    if (list1.val > list2.val) {
      curr_head.next = list2;
      list2 = list2.next;
    } else {
      curr_head.next = list1;
      list1 = list1.next;
    }
    curr_head = curr_head.next;
  }

  curr_head.next = list1 ? list1 : list2;

  return dummy.next;
};


// Solution
/**
 * Solution 1
 *
 * Iteration
 * - Time Complexity: O(N + M)
 * - Space Complexity: O(1)
 *
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var solution1 = function (list1, list2) {
  const dummy = new ListNode(-1);
  let current = dummy;

  while (list1 !== null && list2 !== null) {
    if (list1.val <= list2.val) {
      current.next = list1;
      list1 = list1.next;
    } else {
      current.next = list2;
      list2 = list2.next;
    }
    current = current.next;
  }

  current.next = list1 !== null ? list1 : list2;

  return dummy.next;
};

/**
 * Solution 2
 *
 * Recursion
 * - Time Complexity: O(N + M)
 * - Space Complexity: O(N + M)
 *
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var solution2 = function (list1, list2) {
  if (list1 === null) {
    return list2;
  }
  if (list2 === null) {
    return list1;
  }

  if (list1.val <= list2.val) {
    list1.next = solution2(list1.next, list2);
    return list1;
  } else {
    list2.next = solution2(list1, list2.next);
    return list2;
  }
};
