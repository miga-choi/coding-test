from typing import List


class BinaryWatch:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        result: List = []

        # Hour
        for h in range(12):
            # Minute
            for m in range(60):
                hCount = str(bin(h)[2:]).count("1")
                mCount = str(bin(m)[2:]).count("1")
                if hCount + mCount == turnedOn:
                    if m > 9:
                        result.append(f"{h}:{m}")
                    else:
                        result.append(f"{h}:0{m}")

        return result


    # Solution
    def solution(self, turnedOn: int) -> List[str]:
        return [
            "%d:%02d" % (h, m)
            for h in range(12)
            for m in range(60)
            if (bin(h) + bin(m)).count("1") == turnedOn
        ]
