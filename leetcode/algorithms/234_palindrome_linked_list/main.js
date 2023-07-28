/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

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


// Best Solution
var bestSolution = function (head) {
  let slow = head;
  let fast = head;
  let prev;
  let temp;

  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }

  prev = slow;
  slow = slow.next;
  prev.next = null;

  while (slow) {
    temp = slow.next;
    slow.next = prev;
    prev = slow;
    slow = temp;
  }

  fast = head;
  slow = prev;

  while (slow) {
    if (fast.val !== slow.val) {
      return false;
    } else {
      fast = fast.next;
      slow = slow.next;
    }
  }

  return true;
};
