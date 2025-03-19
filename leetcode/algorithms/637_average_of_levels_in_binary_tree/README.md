# 637. Average of Levels in Binary Tree

Given the `root` of a binary tree, return _the average value of the nodes on each level in the form of an array._ Answers within _10⁻⁵_ of the actual answer will be accepted.

## Example 1:

![alt text](https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
```

## Example 2:

![alt text](https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg)

```
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
```

## Constraints:

- The number of nodes in the tree is in the range `[1, 10⁴]`.
- `-2³¹ <= Node.val <= 2³¹ - 1`
