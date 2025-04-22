function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} leftNode
 * @param {TreeNode} rightNode
 */
function checkNode(leftNode, rightNode) {
  if (!leftNode && !rightNode) {
    return true;
  } else if ((leftNode && !rightNode) || (!leftNode && rightNode)) {
    return false;
  } else if (leftNode.val !== rightNode.val) {
    return false;
  } else {
    return (
      checkNode(leftNode.left, rightNode.right) &&
      checkNode(leftNode.right, rightNode.left)
    );
  }
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function (root) {
  if (!root) {
    return true;
  }
  return checkNode(root.left, root.right);
};


// Solution
// Solution 1
var solution1 = function (root) {
  // Special case...
  if (!root) {
    return true;
  }
  // Return the function recursively...
  return solution1_isSame(root.left, root.right);
};

// A tree is called symmetric if the left subtree must be a mirror reflection of the right subtree...
var solution1_isSame = function (leftroot, rightroot) {
  // If both root nodes are null pointers, return true...
  // If exactly one of them is a null node, return false...
  // If root nodes haven't same value, return false...
  if (
    (!leftroot && rightroot) ||
    (leftroot && !rightroot) ||
    (leftroot && rightroot && leftroot.val !== rightroot.val)
  )
    return false;
  // Return true if the values of root nodes are same and left as well as right subtrees are symmetric...
  if (leftroot && rightroot)
    return (
      isSame(leftroot.left, rightroot.right) &&
      isSame(leftroot.right, rightroot.left)
    );
  return true;
};

// Solution 2: Recursive - Preorder traversal
var solution2 = function (root) {
  if (!root) {
    // Sanity check
    return true;
  }

  // Check if tree s & t are mirroring each other
  function isMirror(s, t) {
    if (!s && !t) {
      return true; // Both nodes are null, ok
    }
    if (!s || !t || s.val !== t.val) {
      return false; // Found a mismatch
    }
    // Compare the left subtree of `s` with the right subtree of `t`
    // and the right subtree of `s` with the left subtree of `t`
    return isMirror(s.left, t.right) && isMirror(s.right, t.left);
  }

  return isMirror(root.left, root.right);
};

// Solution 3: Iterative - Traverse using stack
var solution3 = function (root) {
  if (!root) {
    // Sanity check
    return true;
  }

  // Check if tree s & t are mirroring each other
  function isMirror(p, q) {
    // Create two stacks
    var s1 = [p], s2 = [q];

    // Perform preorder traversal
    while (s1.length > 0 || s2.length > 0) {
      var n1 = s1.pop(), n2 = s2.pop();

      // Two null nodes, let's continue
      if (!n1 && !n2) {
        continue;
      }

      // Return false as long as there is a mismatch
      if (!n1 || !n2 || n1.val !== n2.val) {
        return false;
      }

      // Scan tree s from left to right
      // and scan tree t from right to left
      s1.push(n1.left);
      s1.push(n1.right);
      s2.push(n2.right);
      s2.push(n2.left);
    }

    return true;
  }

  return isMirror(root.left, root.right);
};

// Solution 4: BFS - Traverse both subtrees in level order
var solution4 = function (root) {
  if (!root) {
    // Sanity check
    return true;
  }

  // Check if tree s & t are mirroring each other
  function isMirror(s, t) {
    var q1 = [s], q2 = [t];

    // Perform breadth-first search
    while (q1.length > 0 || q2.length > 0) {
      // Dequeue
      var n1 = q1.shift(), n2 = q2.shift();

      // Two null nodes, let's continue
      if (!n1 && !n2) {
        continue;
      }

      // Return false as long as there is a mismatch
      if (!n1 || !n2 || n1.val !== n2.val) {
        return false;
      }

      // Scan tree s from left to right
      // and scan tree t from right to left
      q1.push(n1.left);
      q1.push(n1.right);
      q2.push(n2.right);
      q2.push(n2.left);
    }

    return true;
  }

  return isMirror(root.left, root.right);
};
