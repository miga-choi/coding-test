import 'dart:collection';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class AverageOfLevelsInBinaryTree {
  List<double> averageOfLevels(TreeNode? root) {
    final List<double> result = List<double>.empty(growable: true);
    final Queue<TreeNode> nodeQueue = Queue<TreeNode>();

    if (root != null) {
      nodeQueue.add(root);
      while (nodeQueue.isNotEmpty) {
        int nodeCount = nodeQueue.length;
        double sum = 0;
        for (int i = 0; i < nodeCount; i++) {
          TreeNode node = nodeQueue.removeFirst();
          sum += node.val;
          if (node.left != null) {
            nodeQueue.add(node.left!);
          }
          if (node.right != null) {
            nodeQueue.add(node.right!);
          }
        }
        result.add(sum / nodeCount);
      }
    }

    return result;
  }

  // Solution
  List<double> solution(TreeNode? root) {
    if (root == null) {
      return [];
    }
    final queue = Queue<TreeNode>();
    queue.add(root);
    List<double> sol = [];
    while (queue.isNotEmpty) {
      int n = queue.length;
      int sum = 0;
      for (int i = 0; i < n; i++) {
        TreeNode node = queue.removeFirst();
        sum += node.val;
        if (node.left != null) {
          queue.add(node.left!);
        }
        if (node.right != null) {
          queue.add(node.right!);
        }
      }
      sol.add(sum / n);
    }
    return sol;
  }
}
