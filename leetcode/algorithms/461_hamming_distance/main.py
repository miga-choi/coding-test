class HammingDistance:
    def hammingDistance(self, x: int, y: int) -> int:
        return len("{0:b}".format(x ^ y).replace("0", ""))


    # Solution
    def solution(self, x: int, y: int) -> int:
        return bin(x ^ y).count("1")
