import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

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
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> prerequisiteToCourses = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            prerequisiteToCourses.add(new ArrayList<>());
        }

        int[] courseNeedPrerequisiteCount = new int[numCourses];

        for (int[] prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteForCourse = prerequisite[1];
            prerequisiteToCourses.get(prerequisiteForCourse).add(course);
            courseNeedPrerequisiteCount[course]++;
        }

        Queue<Integer> courseCanTakeQueue = new LinkedList<>();
        for (int course = 0; course < numCourses; course++) {
            if (courseNeedPrerequisiteCount[course] == 0) {
                courseCanTakeQueue.add(course);
            }
        }

        int courseCompleted = 0;

        while (!courseCanTakeQueue.isEmpty()) {
            int courseTaken = courseCanTakeQueue.poll();
            courseCompleted++;

            for (Integer course : prerequisiteToCourses.get(courseTaken)) {
                courseNeedPrerequisiteCount[course]--;
                if (courseNeedPrerequisiteCount[course] == 0) {
                    courseCanTakeQueue.add(course);
                }
            }
        }

        return courseCompleted == numCourses;
    }


    // Solution
    /**
     * Kahn's Algorithm - BFS
     *
     * Complexities:
     *   V - `numCourses`
     *   E - Size of `prerequisites`
     *   - Time Complexity: O(V + E)
     *   - Space Complexity: O(V + E)
     */
    public boolean solution(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }
        int[] inDegree = new int[numCourses];

        for (int[] pre : prerequisites) {
            int course = pre[0];
            int preReq = pre[1];

            graph.get(preReq).add(course);
            inDegree[course]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        int completedCount = 0;

        while (!queue.isEmpty()) {
            int current = queue.poll();
            completedCount++;

            for (int nextCourse : graph.get(current)) {
                inDegree[nextCourse]--;

                if (inDegree[nextCourse] == 0) {
                    queue.offer(nextCourse);
                }
            }
        }

        return completedCount == numCourses;
    }
}
