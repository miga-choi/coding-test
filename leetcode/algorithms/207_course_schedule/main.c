#include <stdbool.h>
#include <stdlib.h>

// Solution
/**
 * Kahn's Algorithm - BFS
 * 
 * Complexities:
 *   V - `numCourses`
 *   E - `prerequisitesSize`
 *   - Time Complexity: O(V + E)
 *   - Space Complexity: O(V + E)
 */
bool solution(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    int* outDegree = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int pre = prerequisites[i][1];
        outDegree[pre]++;
    }

    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* outIndex = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (outDegree[i] > 0) {
            graph[i] = (int*)malloc(outDegree[i] * sizeof(int));
        } else {
            graph[i] = NULL;
        }
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int crs = prerequisites[i][0];
        int pre = prerequisites[i][1];

        graph[pre][outIndex[pre]++] = crs;
        inDegree[crs]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    int completedCount = 0;
    while (head < tail) {
        int curr = queue[head++];
        completedCount++;

        for (int i = 0; i < outDegree[curr]; i++) {
            int nextCourse = graph[curr][i];
            inDegree[nextCourse]--;

            if (inDegree[nextCourse] == 0) {
                queue[tail++] = nextCourse;
            }
        }
    }

    for (int i = 0; i < numCourses; i++) {
        if (graph[i])
            free(graph[i]);
    }

    free(graph);
    free(inDegree);
    free(outDegree);
    free(outIndex);
    free(queue);

    return completedCount == numCourses;
}
