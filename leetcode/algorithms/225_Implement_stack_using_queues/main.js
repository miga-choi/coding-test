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

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */


// Best Solution
/**
 * Initialize your data structure here.
 */
var BestSolution = function () {
  this.inQueue = [];
  this.outQueue = [];
};

/**
 * Push element x onto stack.
 * @param {number} x
 * @return {void}
 */
BestSolution.prototype.push = function (x) {
  this.inQueue.push(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
BestSolution.prototype.pop = function () {
  while (this.inQueue.length > 1) {
    this.outQueue.push(this.inQueue.shift());
  }

  const lastItem = this.inQueue.shift();

  [this.inQueue, this.outQueue] = [this.outQueue, this.inQueue];

  return lastItem;
};

/**
 * Get the top element.
 * @return {number}
 */
BestSolution.prototype.top = function () {
  while (this.inQueue.length > 1) {
    this.outQueue.push(this.inQueue.shift());
  }
  // peak
  const lastItem = this.inQueue[0];

  this.outQueue.push(this.inQueue.shift());
  [this.inQueue, this.outQueue] = [this.outQueue, this.inQueue];

  return lastItem;
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
BestSolution.prototype.empty = function () {
  return this.inQueue.length === 0;
};
