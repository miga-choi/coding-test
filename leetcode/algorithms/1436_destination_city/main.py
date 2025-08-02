from typing import List, Set


class DestinationCity:
    ##
    # Set
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    #
    def destCity(self, paths: List[List[str]]) -> str:
        cities: Set = set()

        for path in paths:
            cities.add(path[0])

        for path in paths:
            destination: str = path[1]
            if destination not in cities:
                return destination

        return ""


    # Solution
    def solution(self, paths: List[List[str]]) -> str:
        A, B = map(set, zip(*paths))
        return (B - A).pop()
