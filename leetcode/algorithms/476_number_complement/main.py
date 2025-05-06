class NumberComplement:
    def findComplement(self, num: int) -> int:
        binary = "{0:b}".format(num)
        result = ""

        for i in binary:
            if i == "1":
                result += "0"
            else:
                result += "1"

        return int(result, 2)


    # Solution
    def solution(self, num: int) -> int:
        i = 1

        while i <= num:
            i = i << 1

        return (i - 1) ^ num
