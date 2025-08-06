from collections import defaultdict
from typing import Dict, List


class RestoreTheArrayFromAdjacentPairs:
    ###
    # Graph & Hash Map & Vector
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    ##
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        adjacentMap: Dict[int, List[int]] = dict()

        for v1, v2 in adjacentPairs:
            if adjacentMap.get(v1) == None:
                adjacentMap[v1] = list()
            if adjacentMap.get(v2) == None:
                adjacentMap[v2] = list()

            adjacentMap[v1].append(v2)
            adjacentMap[v2].append(v1)

        start: int = 0
        for key in adjacentMap.keys():
            if len(adjacentMap[key]) == 1:
                start = key
                break

        length = len(adjacentPairs) + 1
        result: List[int] = list()

        curr: int = start
        prev: int = -100001

        for _ in range(length):
            result.append(curr)

            neighbors: List[int] = adjacentMap[curr]

            next: int
            if len(neighbors) == 1 or neighbors[0] != prev:
                next = neighbors[0]
            else:
                next = neighbors[1]

            prev = curr
            curr = next

        return result


    # Solution
    def solution(self, pairs: List[List[int]]) -> List[int]:
        # Create a graph to represent adjacent pairs
        graph = defaultdict(list)
        for u, v in pairs:
            graph[u].append(v)
            graph[v].append(u)

        # Initialize the result list
        res = []

        # Find the starting node with only one neighbor
        for node, neighbors in graph.items():
            if len(neighbors) == 1:
                res = [node, neighbors[0]]
                break

        # Continue building the array until its length matches the number of pairs
        while len(res) < len(pairs) + 1:
            # Get the last two elements in the result array
            last, prev = res[-1], res[-2]

            # Find the candidates for the next element
            candidates = graph[last]

            # Choose the candidate that is not the previous element
            next_element = candidates[0] if candidates[0] != prev else candidates[1]

            # Append the next element to the result array
            res.append(next_element)

        return res
