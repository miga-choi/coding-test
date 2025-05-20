/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param3 = obj.contains(key);
 */

class MyHashSet {
  late final List<int> _nums;

  MyHashSet() {
    this._nums = List.filled(1000001, 0);
  }

  void add(int key) {
    this._nums[key] = 1;
  }

  void remove(int key) {
    this._nums[key] = 0;
  }

  bool contains(int key) {
    return this._nums[key] == 1;
  }
}


// Solution
class Solution_MyHashSet {
  final double _loadFactor = 0.7;
  int _itemsNumber = 0;
  int _size = 10;
  List<List<int>> _arr = List<List<int>>.generate(10, (_) => []);

  void add(int key) {
    if (contains(key)) {
      return;
    }

    _arr[key % _size].add(key);
    _itemsNumber++;

    if (_itemsNumber / _size >= _loadFactor) {
      _rehash();
    }
  }

  void _rehash() {
    int newSize = 2 * _size;
    List<List<int>> newArr = List<List<int>>.generate(newSize, (_) => []);

    for (List<int> bucket in _arr) {
      for (int key in bucket) {
        newArr[key % newSize].add(key);
      }
    }

    _size = newSize;
    _arr = newArr;
  }

  void remove(int key) {
    if (contains(key)) {
      _arr[key % _size].remove(key);
      _itemsNumber--;
    }
  }

  bool contains(int key) {
    return _arr[key % _size].contains(key);
  }
}
