/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param2 = obj.pop();
 * int param3 = obj.peek();
 * bool param4 = obj.empty();
 */

class MyQueue {
  late final List<int> input;
  late final List<int> output;

  MyQueue() {
    input = List<int>.empty(growable: true);
    output = List<int>.empty(growable: true);
  }

  // Pushes element `x` to the back of the queue.
  void push(int x) {
    input.add(x);
  }

  // Removes the element from the front of the queue and returns it.
  int pop() {
    peek();
    return output.removeLast();
  }

  // Returns the element at the front of the queue.
  int peek() {
    if (output.isEmpty) {
      while (input.isNotEmpty) {
        output.add(input.removeLast());
      }
    }

    return output.last;
  }

  // Returns `true` if the queue is empty, `false` otherwise.
  bool empty() {
    return input.isEmpty && output.isEmpty;
  }
}


// Solution
class Solution {
  List input = [];

  void push(int x) {
    input.add(x);
  }

  int pop() {
    return input.removeAt(0);
  }

  int peek() {
    return input.first;
  }

  bool empty() {
    return input.isEmpty;
  }
}
