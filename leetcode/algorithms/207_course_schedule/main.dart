import 'dart:collection';

class CourseSchedule {
  /**
   * Kahn's Algorithm - BFS
   *
   * Complexities:
   *   V - `numCourses`
   *   E - Size of `prerequisites`
   *   - Time Complexity: O(V + E)
   *   - Space Complexity: O(V + E)
   */
  bool canFinish(int numCourses, List<List<int>> prerequisites) {
    List<List<int>> prerequisiteToCourse = List.generate(
      numCourses,
      (index) => List<int>.empty(growable: true),
    );
    List<int> coursePrerequisiteCount = List<int>.filled(numCourses, 0);

    for (final [course, prerequisite] in prerequisites) {
      prerequisiteToCourse[prerequisite].add(course);
      coursePrerequisiteCount[course]++;
    }

    Queue<int> courseCanTakeQueue = Queue<int>();
    for (int course = 0; course < numCourses; course++) {
      if (coursePrerequisiteCount[course] == 0) {
        courseCanTakeQueue.add(course);
      }
    }

    int completedCourse = 0;

    while (courseCanTakeQueue.isNotEmpty) {
      int courseTaken = courseCanTakeQueue.removeFirst();
      completedCourse++;

      for (int course in prerequisiteToCourse[courseTaken]) {
        coursePrerequisiteCount[course]--;
        if (coursePrerequisiteCount[course] == 0) {
          courseCanTakeQueue.add(course);
        }
      }
    }

    return completedCourse == numCourses;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Kahn's Algorithm - BFS
   *
   * Complexities:
   *   V - `numCourses`
   *   E - Size of `prerequisites`
   *   - Time Complexity: O(V + E)
   *   - Space Complexity: O(V + E)
   */
  bool solution1(int numCourses, List<List<int>> prerequisites) {
    List<List<int>> adj = List.generate(numCourses, (_) => []);
    List<int> inDegree = List.filled(numCourses, 0);

    for (var pre in prerequisites) {
      int course = pre[0];
      int prereq = pre[1];

      adj[prereq].add(course);
      inDegree[course]++;
    }

    Queue<int> queue = Queue();
    for (int i = 0; i < numCourses; i++) {
      if (inDegree[i] == 0) {
        queue.add(i);
      }
    }

    int takenCourses = 0;

    while (queue.isNotEmpty) {
      int curr = queue.removeFirst();
      takenCourses++;

      for (int nextCourse in adj[curr]) {
        inDegree[nextCourse]--;

        if (inDegree[nextCourse] == 0) {
          queue.add(nextCourse);
        }
      }
    }

    return takenCourses == numCourses;
  }

  /**
   * Solution 2
   * 
   * 3-Color State - DFS
   *
   * Complexities:
   *   V - `numCourses`
   *   E - Size of `prerequisites`
   *   - Time Complexity: O(V + E)
   *   - Space Complexity: O(V + E)
   */
  bool solution2(int numCourses, List<List<int>> prerequisites) {
    List<List<int>> adj = List.generate(numCourses, (_) => []);
    for (var pre in prerequisites) {
      adj[pre[1]].add(pre[0]);
    }

    List<int> state = List.filled(numCourses, 0);

    bool hasCycle(int node) {
      if (state[node] == 1) {
        return true;
      }
      if (state[node] == 2) {
        return false;
      }

      state[node] = 1;

      for (int nextNode in adj[node]) {
        if (hasCycle(nextNode)) {
          return true;
        }
      }

      state[node] = 2;
      return false;
    }

    for (int i = 0; i < numCourses; i++) {
      if (state[i] == 0) {
        if (hasCycle(i)) {
          return false;
        }
      }
    }

    return true;
  }
}
