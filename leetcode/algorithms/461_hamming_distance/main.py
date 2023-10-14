class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return len("{0:b}".format(x ^ y).replace("0", ""))


    # Best Solution
    def bestSolution(self, x: int, y: int) -> int:
        return bin(x ^ y).count("1")
