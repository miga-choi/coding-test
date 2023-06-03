# 171. Excel Sheet Column Number

Given a string `columnTitle` that represents the column title as appears in an Excel sheet, return _its corresponding column number_.

## For example:

```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
```

## Example 1:

```java
Input: columnTitle = "A"
Output: 1
```

## Example 2:

```java
Input: columnTitle = "AB"
Output: 28
```

## Example 3:

```java
Input: columnTitle = "ZY"
Output: 701
```

## Constraints:

- `1 <= columnTitle.length <= 7`
- `columnTitle` consists only of uppercase English letters.
- `columnTitle` is in the range `["A", "FXSHRXW"]`.
