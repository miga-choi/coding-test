class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class ConstructStringFromBinaryTree {
  String tree2str(TreeNode? root) {
    if (root == null) {
      return "";
    }

    String result = root.val.toString();

    if (root.left != null) {
      result += "(${tree2str(root.left)})";
    }

    if (root.right != null) {
      if (root.left == null) {
        result += "()";
      }
      result += "(${tree2str(root.right)})";
    }

    return result;
  }

  // Solution 1: DFS - Without recursion
  String solution1(TreeNode? root) {
    if (root == null) {
      return '';
    }

    // Create an empty stack
    final stack = <TreeNode>[];
    stack.add(root);

    // Create a set to keep track of visited nodes
    final visited = <TreeNode>{};

    final result = StringBuffer();

    while (stack.isNotEmpty) {
      final node = stack.last;

      if (visited.contains(node)) {
        stack.removeLast();
        result.write(')');
      } else {
        visited.add(node);
        result.write('(${node.val}');

        if (node.left == null && node.right != null) {
          result.write('()');
        }

        if (node.right != null) {
          stack.add(node.right!);
        }

        if (node.left != null) {
          stack.add(node.left!);
        }
      }
    }

    // Remove the leading '(' and trailing ')'
    return result.toString().substring(1, result.length - 1);
  }

  // Solution 2
  String solution2(TreeNode? root) {
    if (root == null) {
      return '';
    }

    String result = '${root.val}';

    if (root.left != null || root.right != null) {
      result += '(${tree2str(root.left)})';
    }

    if (root.right != null) {
      result += '(${tree2str(root.right)})';
    }

    return result;
  }
}
