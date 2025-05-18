/**
 * Your MyHashSet object will be instantiated and called as such:
 * var obj = new MyHashSet()
 * obj.add(key)
 * obj.remove(key)
 * var param_3 = obj.contains(key)
 */

var MyHashSet = function () {
  this.nums = Array(1000001).fill(0);
};

/**
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.add = function (key) {
  this.nums[key] = 1;
};

/**
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.remove = function (key) {
  this.nums[key] = 0;
};

/**
 * @param {number} key
 * @return {boolean}
 */
MyHashSet.prototype.contains = function (key) {
  return this.nums[key] === 1;
};


// Solution
var Solution_MyHashSet = function () {
  // Really you should just
  // Make your own object, but instead
  // we have attached ourself to the
  // `this` object which then becomes our hashmap.
  // What you should instead do is this:
  // this.hash_map = {}
  // And then update our following functions
};

Solution_MyHashSet.prototype.add = function (key) {
  // Constant Time
  // Linear Space | To the size of the input key
  // You can access objects using array notation

  this[key] = null;
};

Solution_MyHashSet.prototype.remove = function (key) {
  // Constant Time
  // Constant Space
  // You can access objects using array notation
  // Here we use the delete keyword.

  delete this[key];
};

Solution_MyHashSet.prototype.contains = function (key) {
  // Constant Time
  // Constant Space
  // This just asks if the property exists

  return this.hasOwnProperty(key);
};
