from typing import List


class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        map1: dict = {}
        map2: dict = {}

        for i in range(len(list1)):
            map1.update({list1[i]: i})

        for i in range(len(list2)):
            if map1.get(list2[i]) != None:
                map2.update({list2[i]: map1[list2[i]] + i})

        sortedlist = sorted(map2.items(), key=lambda item: item[1])
        filteredList = list(filter(lambda v: v[1] == sortedlist[0][1], sortedlist))

        return [v[0] for v in filteredList]


    # Best Solution
    # Best Solution 1:
    def bestSolution1(self, list1: List[str], list2: List[str]) -> List[str]:
        Aindex = {u: i for i, u in enumerate(list1)}
        best, ans = 1e9, []

        for j, v in enumerate(list2):
            i = Aindex.get(v, 1e9)
            if i + j < best:
                best = i + j
                ans = [v]
            elif i + j == best:
                ans.append(v)
        return ans

    # Best Solution 2:
    def bestSolution2(self, list1: List[str], list2: List[str]) -> List[str]:
        dic1 = {restaurant: i for i, restaurant in enumerate(list1)}
        dic2 = {restaurant: dic1[restaurant] + i for i, restaurant in enumerate(list2) if restaurant in dic1}

        MIN = float("inf")
        res = []

        for key, val in dic2.items():
            if val < MIN:
                res = [key]
                MIN = val
            elif val == MIN:
                res.append(key)

        return res
