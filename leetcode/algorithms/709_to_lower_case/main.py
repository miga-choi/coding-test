class ToLowerCase:
    def toLowerCase(self, s: str) -> str:
        result: str = ""

        for c in s:
            if ord(c) >= ord("A") and ord(c) <= ord("Z"):
                result += chr(ord(c) + 32)
            else:
                result += c

        return result


    # Solution
    # Solution 1
    def solution1(self, s: str) -> str:
        return "".join(chr(ord(c) + 32) if 65 <= ord(c) <= 90 else c for c in s)

    # Solution 2
    def solution2(self, s: str) -> str:
        return "".join(chr(ord(c) + 32) if "A" <= c <= "Z" else c for c in s)
