import 'dart:collection';

class MyStack {
  late final Queue<int> queue1;
  late final Queue<int> queue2;

  MyStack() {
    queue1 = Queue<int>();
    queue2 = Queue<int>();
  }

  // Pushes element x to the top of the stack.
  void push(int x) {
    while (queue1.isNotEmpty) {
      queue2.add(queue1.removeFirst());
    }
    queue1.add(x);
    while (queue2.isNotEmpty) {
      queue1.add(queue2.removeFirst());
    }
  }

  // Removes the element on the top of the stack and returns it.
  int pop() {
    return queue1.removeFirst();
  }

  // Returns the element on the top of the stack.
  int top() {
    return queue1.first;
  }

  // Returns `true` if the stack is empty, `false` otherwise.
  bool empty() {
    return queue1.isEmpty;
  }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = MyStack();
 * obj.push(x);
 * int param2 = obj.pop();
 * int param3 = obj.top();
 * bool param4 = obj.empty();
 */

class BestSolution {
  List<int> queue1 = [];
  List<int> queue2 = [];
  MyStack() {}

  void push(int x) {
    while (queue1.isNotEmpty) {
      queue2.add(queue1.removeAt(0));
    }
    queue1.add(x);
    while (queue2.isNotEmpty) {
      queue1.add(queue2.removeAt(0));
    }
  }

  int pop() {
    return queue1.removeAt(0);
  }

  int top() {
    return queue1.first;
  }

  bool empty() {
    return queue1.isEmpty;
  }
}
