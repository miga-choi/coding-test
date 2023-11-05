# 506. Relative Ranks

You are given an integer array `score` of size `n`, where `score[i]` is the score of the `iᵗʰ` athlete in a competition. All the scores are guaranteed to be **unique**.

The athletes are **placed** based on their scores, where the `1ˢᵗ` place athlete has the highest score, the `2ⁿᵈ` place athlete has the `2ⁿᵈ` highest score, and so on. The placement of each athlete determines their rank:

- The `1ˢᵗ` place athlete's rank is "`Gold Medal"`.
- The `2ⁿᵈ` place athlete's rank is `"Silver Medal"`.
- The `3ʳᵈ` place athlete's rank is `"Bronze Medal"`.
- For the `4ᵗʰ` place to the `nᵗʰ` place athlete, their rank is their placement number (i.e., the `xᵗʰ` place athlete's rank is `"x"`).

Return an `array` answer of size `n` where `answer[i]` is the **rank** of the `iᵗʰ` athlete.

## Example 1:

```
Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1ˢᵗ, 2ⁿᵈ, 3ʳᵈ, 4ᵗʰ, 5ᵗʰ].
```

## example 2:

```
input: score = [10,3,8,9,4]
output: ["gold medal","5","bronze medal","silver medal","4"]
explanation: the placements are [1ˢᵗ, 5ᵗʰ, 3ʳᵈ, 2ⁿᵈ, 4tᵗʰ].
```

## constraints:

- `n == score.length`
- `1 <= n <= 10⁴`
- `0 <= score[i] <= 10⁶`
- All the values in `score` are **unique**.
