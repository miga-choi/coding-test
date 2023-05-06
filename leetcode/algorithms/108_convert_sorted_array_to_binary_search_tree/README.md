# 108. Convert Sorted Array to Binary Search Tree

Given an integer array `nums` where the elements are sorted in **ascending order**, convert _it to a height-balanced＊ binary search tree_.

**Height-Balanced:** A **height-balanced** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

## Example 1:

![Alt text](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)

```java
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
```

![Alt text](https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg)

## Example 2:

![Alt text](https://assets.leetcode.com/uploads/2021/02/18/btree.jpg)

```java
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
```

## Constraints:

- `1 <= nums.length <= 10⁴`
- `-10⁴ <= nums[i] <= 10⁴`
- `nums` is sorted in a **strictly increasing** order.
