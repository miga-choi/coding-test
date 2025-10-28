from collections import deque
from typing import Optional


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    """
    # Recursion: DFS + Hash table
    # - Time Complexity: O(V + E)
    # - Space Complexity: O(V)
    """
    node_map: dict["Node", "Node"] = {}

    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if node == None:
            return None

        if self.node_map.get(node) != None:
            return self.node_map[node]

        result: Optional["Node"] = Node(node.val)

        self.node_map[node] = result

        for neighbor in node.neighbors:
            result.neighbors.append(self.cloneGraph(neighbor))

        return result


    # Solution
    """
    # Solution 1
    #
    # Recursion: DFS + Hash table
    # - Time Complexity: O(V + E)
    # - Space Complexity: O(V)
    """
    def solution1(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        old_to_new = {}

        def dfs(original_node: "Node") -> "Node":
            if original_node in old_to_new:
                return old_to_new[original_node]

            copy_node = Node(original_node.val)

            old_to_new[original_node] = copy_node

            for neighbor in original_node.neighbors:
                copy_node.neighbors.append(dfs(neighbor))

            return copy_node

        return dfs(node)

    """
    # Solution 2
    #
    # Recursion: DFS + Hash table
    # - Time Complexity: O(V + E)
    # - Space Complexity: O(V)
    """
    def solution2(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        old_to_new = {}

        old_to_new[node] = Node(node.val)
        queue = deque([node])

        while queue:
            original_node = queue.popleft()

            for neighbor in original_node.neighbors:
                if neighbor not in old_to_new:
                    old_to_new[neighbor] = Node(neighbor.val)
                    queue.append(neighbor)

                old_to_new[original_node].neighbors.append(old_to_new[neighbor])

        return old_to_new[node]
