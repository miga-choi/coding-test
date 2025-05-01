import itertools


class CountBinarySubstrings:
    def countBinarySubstrings(self, s: str) -> int:
        count: int = 1
        prevCount: int = 0
        result: int = 0

        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                count += 1
            else:
                result += min(count, prevCount)
                prevCount = count
                count = 1

        return result + min(count, prevCount)


    # Solution
    # Solution 1: Group By Character
    def solution1(self, s: str) -> int:
        groups = [1]
        for i in range(1, len(s)):
            if s[i-1] != s[i]:
                groups.append(1)
            else:
                groups[-1] += 1

        ans = 0
        for i in range(1, len(groups)):
            ans += min(groups[i-1], groups[i])

        return ans

    # Solution 2: Group By Character (Alternate Implentation)
    def solution2(self, s: str) -> int:
        groups = [len(list(v)) for _, v in itertools.groupby(s)]
        return sum(min(a, b) for a, b in zip(groups, groups[1:]))

    # Solution 3: Linear Scan
    def solution3(self, s: str) -> int:
        ans, prev, cur = 0, 0, 1

        for i in range(1, len(s)):
            if s[i-1] != s[i]:
                ans += min(prev, cur)
                prev, cur = cur, 1
            else:
                cur += 1

        return ans + min(prev, cur)
