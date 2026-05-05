from collections import deque
from typing import Optional


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    """
    # DFS
    #
    # Complexities:
    #   V - Number of Vertex in `s`
    #   E - Number of Edge in `s`
    #   - Time Complexity: O(V + E)
    #   - Space Complexity: O(V)
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
    # DFS
    #
    # Complexities:
    #   V - Number of Vertex in `s`
    #   E - Number of Edge in `s`
    #   - Time Complexity: O(V + E)
    #   - Space Complexity: O(V)
    """
    def solution1(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        visited = {}

        def dfs(curr_node):
            if curr_node in visited:
                return visited[curr_node]

            clone_node = Node(curr_node.val)

            visited[curr_node] = clone_node

            for neighbor in curr_node.neighbors:
                clone_node.neighbors.append(dfs(neighbor))

            return clone_node

        return dfs(node)

    """
    # Solution 2
    #
    # BFS
    #
    # Complexities:
    #   V - Number of Vertex in `s`
    #   E - Number of Edge in `s`
    #   - Time Complexity: O(V + E)
    #   - Space Complexity: O(V)
    """
    def solution2(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        visited = {}

        visited[node] = Node(node.val)
        queue = deque([node])

        while queue:
            curr_node = queue.popleft()

            for neighbor in curr_node.neighbors:
                if neighbor not in visited:
                    visited[neighbor] = Node(neighbor.val)
                    queue.append(neighbor)

                visited[curr_node].neighbors.append(visited[neighbor])

        return visited[node]
