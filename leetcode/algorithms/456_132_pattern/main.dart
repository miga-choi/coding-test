import 'dart:math';

class OneThreeTwoPattern {
  bool find132pattern(List<int> nums) {
    int peak = nums.length;
    int min = pow(-10, 9).floor();

    for (int i = nums.length - 1; i >= 0; i--) {
      if (nums[i] < min) {
        return true;
      }
      while (peak < nums.length && nums[i] > nums[peak]) {
        min = nums[peak];
        peak++;
      }
      peak--;
      nums[peak] = nums[i];
    }

    return false;
  }

  // Best Solution
  bool bestSolution(List<int> nums) {
    int n = nums.length;
    List<int> minLeft = List<int>.filled(n, 0);
    int minNum = nums[0];

    for (int i = 0; i < n; i++) {
      minLeft[i] = minNum;
      minNum = min(minNum, nums[i]);
    }

    Stack<int> numbers = Stack<int>();

    for (int j = n - 1; j >= 0; j--) {
      while (numbers.isNotEmpty && nums[j] > numbers.peek) {
        if (numbers.pop() > minLeft[j]) {
          return true;
        }
      }
      numbers.push(nums[j]);
    }

    return false;
  }
}

class Stack<E> {
  final List<E> _list = <E>[];

  void push(E value) => _list.add(value);

  E pop() => _list.removeLast();

  E get peek => _list.last;

  bool get isEmpty => _list.isEmpty;
  bool get isNotEmpty => _list.isNotEmpty;

  @override
  String toString() => _list.toString();
}
