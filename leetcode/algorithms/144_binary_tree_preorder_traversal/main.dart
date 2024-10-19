import 'dart:collection';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class BinaryTreePreorderTraversal {
  void addVal(TreeNode? node, List<int> result) {
    if (node != null) {
      result.add(node.val);
      addVal(node.left, result);
      addVal(node.right, result);
    }
  }

  List<int> preorderTraversal(TreeNode? root) {
    List<int> result = List<int>.empty(growable: true);
    addVal(root, result);
    return result;
  }

  // Best Solution 1: Recursive with helper Function
  void preOrder(TreeNode? root, List<int> list) {
    if (root == null) return;
    list.add(root.val);
    preOrder(root.left, list);
    preOrder(root.right, list);
  }

  List<int> bestSolution1(TreeNode? root) {
    List<int> list = List.empty(growable: true);
    preOrder(root, list);
    return list;
  }

  // Best Solution 2: Recursive without Helper Function
  // Global list to hold our values
  List<int> preorder = List.empty(growable: true);

  List<int> bestSolution2(TreeNode? root) {
    // if tree-node is empty than we will return empty list
    if (root == null) return preorder;
    // else we will add the value into the list
    preorder.add(root.val);
    // adding the value from left side
    preorderTraversal(root.left);
    // adding OR arranging value from right side
    preorderTraversal(root.right);

    return preorder;
  }

  // Best Solution 3: Iterative Approach Using Stack
  List<int> bestSolution3(TreeNode? root) {
    // Create an array list to store the solution result...
    List<int> sol = List.empty(growable: true);
    // Return the solution answer if the tree is empty...
    if (root == null) return sol;
    // Create an empty stack and push the root node...
    Queue<TreeNode?> bag = Queue();
    bag.add(root);
    // Loop till stack is empty...
    while (!bag.isEmpty) {
      // Pop a node from the stack...
      TreeNode? node = bag.removeLast();
      sol.add(node!.val);
      // Push the right child of the popped node into the stack...
      if (node.right != null) bag.add(node.right);
      // Push the left child of the popped node into the stack...
      if (node.left != null) bag.add(node.left);
    }
    return sol; // Return the solution list...
  }
}
