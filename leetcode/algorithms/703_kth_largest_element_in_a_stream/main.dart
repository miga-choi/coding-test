import 'dart:collection';

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = KthLargest(k, nums);
 * int param1 = obj.add(val);
 */

class KthLargest {
  late final List<int> _list;
  late final int _k;

  KthLargest(int k, List<int> nums) {
    _list = new List.empty(growable: true);
    _k = k;
    for (int num in nums) {
      add(num);
    }
  }

  int add(int val) {
    if (_list.isEmpty) {
      _list.add(val);
    } else {
      if (_list.last >= val) {
        _list.add(val);
      } else {
        for (int i = 0; i < _list.length; i++) {
          if (_list[i] < val) {
            _list.insert(i, val);
            break;
          }
        }
      }
      if (_list.length > _k) {
        _list.removeLast();
      }
    }
    return _list.last;
  }
}


// Solution
// Solution 1
class Solution1_KthLargest {
  final int k;
  final stm = SplayTreeMap<int, int>((a, b) => a.compareTo(b));
  int cnt = 0;

  Solution1_KthLargest(this.k, List<int> nums) {
    for (final n in nums) {
      stm[n] = (stm[n] ?? 0) + 1;
      cnt++;
    }
  }

  int add(int val) {
    stm[val] = (stm[val] ?? 0) + 1;
    cnt++;
    while (cnt > k) {
      final firstKey = stm.firstKey()!;
      stm[firstKey] = stm[firstKey]! - 1;
      if (stm[firstKey] == 0) {
        stm.remove(firstKey);
      }
      cnt--;
    }
    return stm.firstKey()!;
  }
}

// Solution 2
class Solution2_KthLargest {
  late MinHeap heap;
  late int k;

  Solution2_KthLargest(int k, List<int> nums) {
    heap = MinHeap(nums);
    this.k = k;

    while (heap.length > k) {
      heap.pop();
    }
  }

  int add(int val) {
    heap.push(val);

    if (heap.length > k) {
      heap.pop();
    }

    return heap.first;
  }
}

class MinHeap {
  List<int> _heap = [-1];

  MinHeap(List<int>? nums) {
    if (nums == null || nums.isEmpty) {
      return;
    }

    _heap.addAll(nums);

    for (int cur = (_heap.length - 1) ~/ 2; cur > 0; cur--) {
      int i = cur;

      while (2 * i < _heap.length) {
        int left = 2 * i;
        int right = 2 * i + 1;

        if (_hasRightChild(i) &&
            _heap[i] > _heap[right] &&
            _isRightSmallerThenLeft(i)) {
          _swap(i, right);
          i = right;
        } else if (_heap[i] > _heap[left]) {
          _swap(i, left);
          i = left;
        } else {
          break;
        }
      }
    }
  }

  int get length => _heap.length - 1;

  int get first => _heap[1];

  void push(int val) {
    _heap.add(val);
    int i = _heap.length - 1;

    while (i > 1 && _heap[i] < _heap[i ~/ 2]) {
      _swap(i, i ~/ 2);
      i = i ~/ 2;
    }
  }

  int? pop() {
    if (_heap.length == 1) {
      return null;
    }

    if (_heap.length == 2) {
      return _heap.removeAt(1);
    }

    int res = _heap[1];
    _heap[1] = _heap.removeLast();
    int i = 1;

    while (2 * i < _heap.length) {
      int left = 2 * i;
      int right = 2 * i + 1;

      if (_hasRightChild(i) &&
          _heap[i] > _heap[right] &&
          _isRightSmallerThenLeft(i)) {
        _swap(i, right);
        i = right;
      } else if (_heap[i] > _heap[left]) {
        _swap(i, left);
        i = left;
      } else {
        break;
      }
    }

    return res;
  }

  bool _hasRightChild(int i) {
    return 2 * i + 1 < _heap.length;
  }

  bool _isRightSmallerThenLeft(int i) {
    return _heap[2 * i + 1] < _heap[2 * i];
  }

  void _swap(int n, int m) {
    int tmp = _heap[n];
    _heap[n] = _heap[m];
    _heap[m] = tmp;
  }
}

// Solution 3
class Solution3_KthLargest {
  var _k = 0;
  var _nums = <int>[];

  Solution3_KthLargest(int k, List<int> nums) {
    _k = k;
    nums.sort((a, b) => b.compareTo(a));
    _nums = nums.take(_k).toList();
  }

  int add(int val) {
    var flag = _nums.length < _k;
    if (flag || val > _nums.last) {
      if (flag) {
        _nums
          ..add(val)
          ..sort((a, b) => b.compareTo(a));
      } else {
        _nums
          ..insert(_nums.indexWhere((e) => val > e), val)
          ..removeLast();
      }
    }
    return _nums.last;
  }
}
