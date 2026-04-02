#include <queue>
#include <vector>
using namespace std;

class CourseSchedule {
public:
    /**
     * Kahn's Algorithm - BFS
     *
     * Complexities:
     *   V - `numCourses`
     *   E - Size of `prerequisites`
     *   - Time Complexity: O(V + E)
     *   - Space Complexity: O(V + E)
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prerequisiteToCourse(numCourses);
        vector<int> remainedCourseCount(numCourses, 0);

        for (vector<int>& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteForCourse = prerequisite[1];

            prerequisiteToCourse[prerequisiteForCourse].push_back(course);
            remainedCourseCount[course]++;
        }

        queue<int> courseCanTakeQueue;
        for (int course = 0; course < numCourses; course++) {
            if (remainedCourseCount[course] == 0) {
                courseCanTakeQueue.push(course);
            }
        }

        int completedCourseCount = 0;

        while (!courseCanTakeQueue.empty()) {
            int completedCourse = courseCanTakeQueue.front();
            courseCanTakeQueue.pop();
            completedCourseCount++;

            for (int course : prerequisiteToCourse[completedCourse]) {
                remainedCourseCount[course]--;

                if (remainedCourseCount[course] == 0) {
                    courseCanTakeQueue.push(course);
                }
            }
        }

        return completedCourseCount == numCourses;
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
    bool solution(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            
            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int completedCount = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCount++;

            for (int nextCourse : adj[curr]) {
                inDegree[nextCourse]--;
                
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        return completedCount == numCourses;
    }
};
