import re
from typing import List


class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        result = []
        for word in words:
            row = 0
            if len(word) == 1:
                result.append(word)
            else:
                wordLower = word.lower()
                isTrue = True
                for c in wordLower:
                    if row == 0:
                        if "qwertyuiop".count(c) > 0:
                            row = 1
                        elif "asdfghjkl".count(c) > 0:
                            row = 2
                        elif "zxcvbnm".count(c) > 0:
                            row = 3
                    else:
                        if row == 1 and "qwertyuiop".count(c) == 0:
                            isTrue = False
                            break
                        elif row == 2 and "asdfghjkl".count(c) == 0:
                            isTrue = False
                            break
                        elif row == 3 and "zxcvbnm".count(c) == 0:
                            isTrue = False
                            break
                if isTrue:
                    result.append(word)
        return result


    # Best Solution
    def bestSolution1(self, words: List[str]) -> List[str]:
        line1, line2, line3 = set("qwertyuiop"), set("asdfghjkl"), set("zxcvbnm")
        ret = []
        for word in words:
            w = set(word.lower())
            if w <= line1 or w <= line2 or w <= line3:
                ret.append(word)
        return ret

    def bestSolution2(self, words: List[str]) -> List[str]:
        return filter(re.compile("(?i)([qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*)$").match, words)
