/**
 * Kahn's Algorithm - BFS
 *
 * Complexities:
 *   V - `numCourses`
 *   E - Size of `prerequisites`
 *   - Time Complexity: O(V + E)
 *   - Space Complexity: O(V + E)
 */
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function (numCourses, prerequisites) {
  const prerequisiteToCourse = Array.from(
    { length: numCourses },
    () => new Array(),
  );
  const remainedCourseCount = new Array(numCourses).fill(0);

  for (const [course, prerequisite] of prerequisites) {
    prerequisiteToCourse[prerequisite].push(course);
    remainedCourseCount[course]++;
  }

  const courseCanTakeQueue = new Array();
  for (let course = 0; course < numCourses; course++) {
    if (remainedCourseCount[course] === 0) {
      courseCanTakeQueue.push(course);
    }
  }

  let completedCourseCount = 0;

  while (courseCanTakeQueue.length > 0) {
    const completedCourse = courseCanTakeQueue.shift();
    completedCourseCount++;

    for (const course of prerequisiteToCourse[completedCourse]) {
      remainedCourseCount[course]--;

      if (remainedCourseCount[course] === 0) {
        courseCanTakeQueue.push(course);
      }
    }
  }

  return completedCourseCount === numCourses;
};


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
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var solution1 = function (numCourses, prerequisites) {
  const inDegree = new Array(numCourses).fill(0);
  const adjList = Array.from({ length: numCourses }, () => []);

  for (const [course, pre] of prerequisites) {
    adjList[pre].push(course);
    inDegree[course]++;
  }

  const queue = [];
  for (let i = 0; i < numCourses; i++) {
    if (inDegree[i] === 0) {
      queue.push(i);
    }
  }

  let count = 0;

  while (queue.length > 0) {
    const current = queue.shift();
    count++;

    for (const nextCourse of adjList[current]) {
      inDegree[nextCourse]--;

      if (inDegree[nextCourse] === 0) {
        queue.push(nextCourse);
      }
    }
  }

  return count === numCourses;
};

/**
 * Solution 2
 *
 * DFS
 *
 * Complexities:
 *   V - `numCourses`
 *   E - Size of `prerequisites`
 *   - Time Complexity: O(V + E)
 *   - Space Complexity: O(V + E)
 */
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var solution2 = function (numCourses, prerequisites) {
  const adjList = Array.from({ length: numCourses }, () => []);
  for (const [course, pre] of prerequisites) {
    adjList[pre].push(course);
  }

  const state = new Array(numCourses).fill(0);

  function hasCycle(node) {
    if (state[node] === 1) {
      return true;
    }
    if (state[node] === 2) {
      return false;
    }

    state[node] = 1;

    for (const nextCourse of adjList[node]) {
      if (hasCycle(nextCourse)) {
        return true;
      }
    }

    state[node] = 2;
    return false;
  }

  for (let i = 0; i < numCourses; i++) {
    if (state[i] === 0) {
      if (hasCycle(i)) {
        return false;
      }
    }
  }

  return true;
};
