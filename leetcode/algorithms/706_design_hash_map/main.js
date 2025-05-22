/**
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */

var MyHashMap = function () {
  this.nums = Array(1e6 + 1).fill(-1);
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
MyHashMap.prototype.put = function (key, value) {
  this.nums[key] = value;
};

/**
 * @param {number} key
 * @return {number}
 */
MyHashMap.prototype.get = function (key) {
  return this.nums[key];
};

/**
 * @param {number} key
 * @return {void}
 */
MyHashMap.prototype.remove = function (key) {
  this.nums[key] = -1;
};


// Solution
// Solution 1: Array
class Solution1_MyHashMap {
  constructor() {
    this.data = new Array(1000001);
  }

  put(key, val) {
    this.data[key] = val;
  }

  get(key) {
    let val = this.data[key];
    return val !== undefined ? val : -1;
  }

  remove(key) {
    delete this.data[key];
  }
}

// Solution 2: Hash
class ListNode {
    constructor(key, val, next) {
        this.key = key;
        this.val = val;
        this.next = next;
    }
}

class Solution2_MyHashMap {
    constructor() {
        this.size = 19997;
        this.mult = 12582917;
        this.data = new Array(this.size);
    }

    hash(key) {
        return (key * this.mult) % this.size;
    }

    put(key, val) {
        this.remove(key);
        let h = this.hash(key);
        let node = new ListNode(key, val, this.data[h]);
        this.data[h] = node;
    }

    get(key) {
        let h = this.hash(key), node = this.data[h];

        for (; node; node = node.next) {
            if (node.key === key) {
                return node.val;
            }
        }

        return -1;
    }

    remove(key) {
        let h = this.hash(key), node = this.data[h];

        if (!node) {
            return;
        }

        if (node.key === key) {
            this.data[h] = node.next;
        } else {
            for (; node.next; node = node.next) {
                if (node.next.key === key) {
                    node.next = node.next.next;
                    return;
                }
            }
        }
    }
}