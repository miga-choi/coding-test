# 58. Length of Last Word

Given a string `s` consisting of words and spaces, return the length of the **_last_** word in the string.

A **_word_** is a maximal
[substring](A **_substring_** is a contiguous non-empty sequence of characters within a string.)
consisting of non-space characters only.

## Example 1:

```javascript
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
```

## Example 2:

```javascript
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
```

## Example 3:

```javascript
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
```

## Constraints:

- `1 <= s.length <= 10⁴`
- `s` consists of only English letters and spaces `' '`.
- There will be at least one word in `s`.
