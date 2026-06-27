/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */

/**
 * Complexities:
 *   - Time Complexity:
 *     push: O(N)
 *     pop: O(1)
 *     top: O(1)
 *     empty: O(1)
 *   - Space Complexity: O(N)
 */
var MyStack = function () {
  this.inputStack = [];
  this.outputStack = [];
};

/**
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function (x) {
  if (this.inputStack.length > 0) {
    this.outputStack.push(this.inputStack.pop());
  }
  this.inputStack.push(x);
};

/**
 * @return {number}
 */
MyStack.prototype.pop = function () {
  if (this.inputStack.length > 0) {
    return this.inputStack.pop();
  } else {
    return this.outputStack.pop();
  }
};

/**
 * @return {number}
 */
MyStack.prototype.top = function () {
  if (this.inputStack.length > 0) {
    return this.inputStack[0];
  } else {
    return this.outputStack[this.outputStack.length - 1];
  }
};

/**
 * @return {boolean}
 */
MyStack.prototype.empty = function () {
  if (this.inputStack.length > 0 || this.outputStack.length > 0) {
    return false;
  } else {
    return true;
  }
};


// Solution
/**
 * Complexities:
 *   - Time Complexity:
 *     push: O(N)
 *     pop: O(1)
 *     top: O(1)
 *     empty: O(1)
 *   - Space Complexity: O(N)
 */
class Solution {
  constructor() {
    this.queue = [];
  }

  push(x) {
    this.queue.push(x);

    let size = this.queue.length - 1;

    while (size > 0) {
      this.queue.push(this.queue.shift());
      size--;
    }
  }

  pop() {
    return this.queue.shift();
  }

  top() {
    return this.queue[0];
  }

  empty() {
    return this.queue.length === 0;
  }
}
