from collections import deque
from typing import List


class CourseSchedule:
    """
    # Kahn's Algorithm - BFS
    #
    # Complexities:
    #   V - `numCourses`
    #   E - Size of `prerequisites`
    #   - Time Complexity: O(V + E)
    #   - Space Complexity: O(V + E)
    """
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        prerequisiteToCourse: List[List[int]] = []
        for _ in range(numCourses):
            prerequisiteToCourse.append([])

        courseNeedPrerequisiteCount: List[int] = [0] * numCourses

        for [course, prerequisite] in prerequisites:
            prerequisiteToCourse[prerequisite].append(course)
            courseNeedPrerequisiteCount[course] += 1

        courseCanTakeQueue: List[int] = []

        for course in range(numCourses):
            if courseNeedPrerequisiteCount[course] == 0:
                courseCanTakeQueue.append(course)

        courseCompletedCount: int = 0
        while len(courseCanTakeQueue) > 0:
            courseTaken: int = courseCanTakeQueue.pop(0)
            courseCompletedCount += 1

            for course in prerequisiteToCourse[courseTaken]:
                courseNeedPrerequisiteCount[course] -= 1
                if courseNeedPrerequisiteCount[course] == 0:
                    courseCanTakeQueue.append(course)

        return courseCompletedCount == numCourses


    # Solution
    """
    # Solution 1
    #
    # Kahn's Algorithm - BFS
    #
    # Complexities:
    #   V - `numCourses`
    #   E - Size of `prerequisites`
    #   - Time Complexity: O(V + E)
    #   - Space Complexity: O(V + E)
    """
    def solution1(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        in_degree = [0] * numCourses

        for course, pre in prerequisites:
            graph[pre].append(course)
            in_degree[course] += 1

        queue = deque([i for i in range(numCourses) if in_degree[i] == 0])

        completed_courses = 0

        while queue:
            curr = queue.popleft()
            completed_courses += 1

            for next_course in graph[curr]:
                in_degree[next_course] -= 1

                if in_degree[next_course] == 0:
                    queue.append(next_course)

        return completed_courses == numCourses

    """
    # Solution 2
    #
    # 3-Color State - DFS
    #
    # Complexities:
    #   V - `numCourses`
    #   E - Size of `prerequisites`
    #   - Time Complexity: O(V + E)
    #   - Space Complexity: O(V + E)
    """
    def solution2(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        for course, pre in prerequisites:
            graph[pre].append(course)

        visited = [0] * numCourses

        def dfs(curr: int) -> bool:
            if visited[curr] == 1:
                return False
            if visited[curr] == 2:
                return True

            visited[curr] = 1

            for next_course in graph[curr]:
                if not dfs(next_course):
                    return False

            visited[curr] = 2
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False

        return True
