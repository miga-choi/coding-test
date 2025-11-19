#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Brute-force
 * 
 * Complexities:
 *   N - size of strs
 *   K - max size of strings in strs
 *   - Time Complexity: O(N² * K) - Time Limit Exceeded
 *   - Space Complexity: O(N * K)
 */
 char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    // For skipping visited str
    int* visited = (int*)calloc(strsSize, sizeof(int));

    int result_capacity = 8;
    char*** result = (char***)malloc(sizeof(char**) * result_capacity);
    int* items_size_array = (int*)malloc(sizeof(int) * result_capacity);

    *returnSize = 0;

    for (int i = 0; i < strsSize; i++) {
        // Skip if visited
        if (visited[i]) {
            continue;
        }

        // Realloc result's capacity
        if (*returnSize >= result_capacity) {
            result_capacity *= 2;
            result = (char***)realloc(result, sizeof(char**) * result_capacity);
            items_size_array = (int*)realloc(items_size_array, sizeof(int) * result_capacity);
        }

        int group_map[26] = {0};
        int group_item_len = strlen(strs[i]);

        int group_capacity = 8;
        result[*returnSize] = (char**)malloc(sizeof(char*) * group_capacity);
        int index = 0;

        for (int j = 0; j < group_item_len; j++) {
            group_map[strs[i][j] - 'a']++;
        }

        // First item must add to group
        result[*returnSize][index] = (char*)malloc(sizeof(char) * (group_item_len + 1));
        strcpy(result[*returnSize][index], strs[i]);
        visited[i] = 1;
        index++;
        items_size_array[*returnSize] = index;

        // Items loop
        for (int j = 0; j < strsSize; j++) {
            // Skip if visited
            if (visited[j]) {
                continue;
            }

            // Realloc group's capacity
            if (index >= group_capacity) {
                group_capacity *= 2;
                result[*returnSize] = (char**)realloc(result[*returnSize], sizeof(char*) * group_capacity);
            }

            int item_map[26] = {0};
            int item_len = strlen(strs[j]);

            for (int k = 0; k < item_len; k++) {
                item_map[strs[j][k] - 'a']++;
            }

            // Check item
            int add_item = 1;
            for (int k = 0; k < 26; k++) {
                if (group_map[k] != item_map[k]) {
                    add_item = 0;
                    break;
                }
            }

            // Add item
            if (add_item) {
                result[*returnSize][index] = (char*)malloc(sizeof(char) * (item_len + 1));
                strcpy(result[*returnSize][index], strs[j]);
                visited[j] = 1;
                index++;
                items_size_array[*returnSize] = index;
            }
        }

        (*returnSize)++;
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));

    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = items_size_array[i];
    }

    return result;
}
