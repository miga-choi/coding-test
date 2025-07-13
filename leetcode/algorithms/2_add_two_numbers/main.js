function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

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
var solution = function (l1, l2) {
  const iter = (n1, n2, rest = 0) => {
    if (!n1 && !n2 && !rest) {
      return null;
    }

    const newVal = (n1?.val || 0) + (n2?.val || 0) + rest;
    const nextNode = iter(n1?.next, n2?.next, Math.floor(newVal / 10));

    return new ListNode(newVal % 10, nextNode);
  }

  return iter(l1, l2);
};
