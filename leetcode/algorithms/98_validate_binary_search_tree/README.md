# 98. Validate Binary Search Tree

Given the `root` of a binary tree, _determine if it is a valid binary search tree (BST)_.

A **valid BST** is defined as follows:

- The left subtree of a node contains only nodes with keys **strictly less than** the node's key.
- The right subtree of a node contains only nodes with keys **strictly greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Subtree**: A subtree of `treeName` is a tree consisting of a node in `treeName` and all of its descendants.

## Example 1:

![Example 1](example1.png)

```
Input: root = [2,1,3]
Output: true
```

## Example 2:

![Example 2](example2.png)

```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

## Constraints:

- The number of nodes in the tree is in the range `[1, 10⁴]`.
- `-2³¹ <= Node.val <= 2³¹ - 1`
