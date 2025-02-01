# 521. Longest Uncommon Subsequence I

Given two strings `a` and `b`, return _the length of the **longest uncommon subsequence** between_ `a` _and_ `b`. If the longest uncommon subsequence does not exist, return `-1`.

An **uncommon subsequence** between two strings is a string that is a **[subsequence](## "A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.") of one but not the other**.


## Example 1:

```
Input: a = "aba", b = "cdc"
Output: 3
Explanation: One longest uncommon subsequence is "aba" because "aba" is a subsequence of "aba" but not "cdc".
Note that "cdc" is also a longest uncommon subsequence.
```

## Example 2:

```
Input: a = "aaa", b = "bbb"
Output: 3
Explanation: The longest uncommon subsequences are "aaa" and "bbb".
```

## Example 3:

```
Input: a = "aaa", b = "aaa"
Output: -1
Explanation: Every subsequence of string a is also a subsequence of string b. Similarly, every subsequence of string b is also a subsequence of string a.
```

## Constraints:

- `1 <= a.length, b.length <= 100`
- `a` and `b` consist of lower-case English letters.
