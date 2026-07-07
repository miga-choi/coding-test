/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */

/**
 * Complexities:
 *   - Time Complexity:
 *     push(x): O(1)
 *     pop(): O(1)
 *     peek(): O(1)
 *     empty(): O(1)
 *   - Space Complexity: O(N)
 */
var MyQueue = function () {
  this.inputStack = [];
  this.outputStack = [];
};

/**
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function (x) {
  this.inputStack.push(x);
};

/**
 * @return {number}
 */
MyQueue.prototype.pop = function () {
  if (this.outputStack.length == 0) {
    while (this.inputStack.length > 0) {
      this.outputStack.push(this.inputStack.pop());
    }
  }
  return this.outputStack.pop();
};

/**
 * @return {number}
 */
MyQueue.prototype.peek = function () {
  if (this.outputStack.length > 0) {
    return this.outputStack[this.outputStack.length - 1];
  }
  return this.inputStack[0];
};

/**
 * @return {boolean}
 */
MyQueue.prototype.empty = function () {
  if (this.inputStack.length === 0 && this.outputStack.length === 0) {
    return true;
  }
  return false;
};


// Solution
/**
 * Complexities:
 *   - Time Complexity:
 *     push(x): O(1)
 *     pop(): O(1)
 *     peek(): O(1)
 *     empty(): O(1)
 *   - Space Complexity: O(N)
 */
class Solution {
  constructor() {
    this.inStack = [];
    this.outStack = [];
  }

  push(x) {
    this.inStack.push(x);
  }

  pop() {
    this.moveInToOut();
    return this.outStack.pop();
  }

  peek() {
    this.moveInToOut();
    return this.outStack[this.outStack.length - 1];
  }

  empty() {
    return this.inStack.length === 0 && this.outStack.length === 0;
  }

  moveInToOut() {
    if (this.outStack.length === 0) {
      while (this.inStack.length > 0) {
        this.outStack.push(this.inStack.pop());
      }
    }
  }
}
