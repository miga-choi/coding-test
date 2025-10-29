#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

/**
 * Recursion: DFS + Array
 * - Time Complexity: O(V + E)
 * - Space Complexity: O(V)
 */
struct Node* getClonedNode(struct Node** node_array, struct Node* origin) {
    if (origin == NULL) {
        return NULL;
    }

    if (node_array[origin->val - 1] != NULL) {
        return node_array[origin->val - 1];
    }

    struct Node* cloned = (struct Node*)malloc(sizeof(struct Node));

    cloned->val = origin->val;
    cloned->numNeighbors = origin->numNeighbors;
    cloned->neighbors = (struct Node**)malloc(sizeof(struct Node*) * origin->numNeighbors);

    node_array[origin->val - 1] = cloned;

    for (int i = 0; i < origin->numNeighbors; i++) {
        cloned->neighbors[i] = getClonedNode(node_array, origin->neighbors[i]);
    }

    return cloned;
}

struct Node* cloneGraph(struct Node* s) {
    struct Node** node_array = (struct Node**)calloc(100, sizeof(struct Node*));
    return getClonedNode(node_array, s);
}


// Solution
/**
 * Recursion: DFS + Array
 * - Time Complexity: O(V + E)
 * - Space Complexity: O(V)
 */
struct Node* dfs(struct Node** visited_map, struct Node* original_node) {
    if (original_node == NULL) {
        return NULL;
    }

    if (visited_map[original_node->val - 1] != NULL) {
        return visited_map[original_node->val - 1];
    }

    struct Node* cloned_node = (struct Node*)malloc(sizeof(struct Node));
    if (cloned_node == NULL)
        return NULL;

    cloned_node->val = original_node->val;
    cloned_node->numNeighbors = original_node->numNeighbors;
    cloned_node->neighbors = (struct Node**)malloc(sizeof(struct Node*) * original_node->numNeighbors);
    if (cloned_node->neighbors == NULL) {
        free(cloned_node);
        return NULL;
    }

    visited_map[original_node->val - 1] = cloned_node;

    for (int i = 0; i < original_node->numNeighbors; i++) {
        cloned_node->neighbors[i] =
            dfs(visited_map, original_node->neighbors[i]);
    }

    return cloned_node;
}

struct Node* solution(struct Node* s) {
    struct Node** visited_map = (struct Node**)calloc(101, sizeof(struct Node*));
    if (visited_map == NULL)
        return NULL;

    struct Node* result = dfs(visited_map, s);

    free(visited_map);

    return result;
}
