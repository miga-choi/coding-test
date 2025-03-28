# 598. Range Addition II

You are given an `m x n` matrix `M` initialized with all `0`'s and an array of operations `ops`, where `ops[i] = [aᵢ, bᵢ]` means `M[x][y]` should be incremented by one for all `0 <= x < aᵢ` and `0 <= y < bᵢ`.

Count and return _the number of maximum integers in the matrix after performing all the operations_.

## Example 1:

![Example 1](example1.png)

```
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.
```

## Example 2:

```
Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4
```

## Example 3:

```
Input: m = 3, n = 3, ops = []
Output: 9
```

## Constraints:

- `1 <= m, n <= 4 * 10⁴`
- `0 <= ops.length <= 10⁴`
- `ops[i].length == 2`
- `1 <= aᵢ <= m`
- `1 <= bᵢ <= n`
