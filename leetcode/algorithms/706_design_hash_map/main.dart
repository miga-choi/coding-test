/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = MyHashMap();
 * obj.put(key,value);
 * int param2 = obj.get(key);
 * obj.remove(key);
 */

class MyHashMap {
  late final List<int> _nums;

  MyHashMap() {
    this._nums = List<int>.filled(1000001, -1);
  }

  void put(int key, int value) {
    this._nums[key] = value;
  }

  int get(int key) {
    return this._nums[key];
  }

  void remove(int key) {
    this._nums[key] = -1;
  }
}


// Solution
class _Item {
  final int key;
  int value;
  _Item? next = null;
  _Item(this.key, this.value);
}

class Solution_MyHashMap {
  late final List<_Item> db = List.generate(1000, (_) => _Item(-1, -1));

  Solution_MyHashMap() {}

  int getkey(int key) => key % 1000;

  void put(int key, int value) {
    var cur = db[getkey(key)];

    while (cur.next != null) {
      if (cur.next!.key == key) {
        cur.next!.value = value;
        return;
      }
      cur = cur.next!;
    }

    cur.next = _Item(key, value);
  }

  int get(int key) {
    var cur = db[getkey(key)];

    while (cur.next != null) {
      if (cur.next!.key == key) return cur.next!.value;
      cur = cur.next!;
    }

    return -1;
  }

  void remove(int key) {
    var cur = db[getkey(key)];

    while (cur.next != null) {
      if (cur.next!.key == key) {
        cur.next = cur.next!.next;
        return;
      }
      cur = cur.next!;
    }
  }
}
