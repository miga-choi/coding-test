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

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */

// Best Solution
var BestSolution = function () {
  this.stack1 = [];
  this.stack2 = [];
  this.front = null;
};

/**
 * @param {number} x
 * @return {void}
 */
BestSolution.prototype.push = function (x) {
  if (this.stack1.length == 0) {
    this.front = x;
  }
  this.stack1.push(x);
};

/**
 * @return {number}
 */
BestSolution.prototype.pop = function () {
  if (this.stack2.length == 0) {
    while (this.stack1.length != 0) {
      this.stack2.push(this.stack1.pop());
    }
  }
  return this.stack2.pop();
};

/**
 * @return {number}
 */
BestSolution.prototype.peek = function () {
  return this.stack2.length == 0
    ? this.front
    : this.stack2[this.stack2.length - 1];
};

/**
 * @return {boolean}
 */
BestSolution.prototype.empty = function () {
  return this.stack1.length == 0 && this.stack2.length == 0;
};
