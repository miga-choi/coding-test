class WordPattern:
    def wordPattern(self, pattern: str, s: str) -> bool:
        sArray: list = s.split(" ")

        if len(sArray) != len(pattern):
            return False

        sMap: dict = {}

        for i in range(len(pattern)):
            if sMap.get(pattern[i]) == None:
                for v in list(sMap.values()):
                    if sArray[i] == v:
                        return False
                sMap.update({pattern[i]: sArray[i]})
            else:
                if sMap[pattern[i]] != sArray[i]:
                    return False

        return True


    # Solution
    def solution(self, pattern: str, str: str) -> bool:
        # dictionary approach
        # Time complexity: O(n)
        # Space complexity: O(n)

        words = str.split(" ")
        if not len(words) == len(pattern):
            return False

        mapping = dict()  # key is the pattern, value is the word

        for i in range(len(words)):
            if pattern[i] not in mapping:
                # values() is a set - fast membership testing - O(1) amortised search
                if words[i] not in mapping.values():
                    mapping[pattern[i]] = words[i]
                else:
                    return False
            else:
                if not mapping[pattern[i]] == words[i]:
                    return False

        return True
