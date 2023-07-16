# 219. Contains Duplicate II

Given an integer array `nums` and an integer `k`, return `true` _if there are two **distinct indices**_ `i` _and_ `j` _in the array such that_ `nums[i] == nums[j]` _and_ `abs(i - j) <= k`.

## Example 1:

```
Input: nums = [1,2,3,1], k = 3
Output: true
```

## Example 2:

```
Input: nums = [1,0,1,1], k = 1
Output: true
```

## Example 3:

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

## Constraints:

- `1 <= nums.length <= 10⁵`
- `-10⁹ <= nums[i] <= 10⁹`
- `0 <= k <= 10⁵`
