from typing import Counter


class RansomNote:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazineMap: dict = {}

        for c in magazine:
            if magazineMap.get(c) != None:
                magazineMap.update({c: magazineMap.get(c) + 1})
            else:
                magazineMap.update({c: 1})

        for c in ransomNote:
            if magazineMap.get(c) != None and magazineMap.get(c) > 0:
                magazineMap.update({c: magazineMap.get(c) - 1})
            else:
                return False

        return True


    # Solution
    def solution(self, ransomNote, magazine):
        st1, st2 = Counter(ransomNote), Counter(magazine)
        if st1 & st2 == st1:
            return True
        return False
