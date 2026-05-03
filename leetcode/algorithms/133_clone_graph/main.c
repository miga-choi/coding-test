#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

/**
 * Recursion - DFS
 * 
 * Complexities:
 *   V - Number of Vertex in `s`
 *   E - Number of Edge in `s`
 *   - Time Complexity: O(V + E)
 *   - Space Complexity: O(V)
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
 * Recursion - DFS
 * 
 * Complexities:
 *   V - Number of Vertex in `s`
 *   E - Number of Edge in `s`
 *   - Time Complexity: O(V + E)
 *   - Space Complexity: O(V)
 */
struct Node* dfs_clone(struct Node* node, struct Node** visited) {
    if (node == NULL) {
        return NULL;
    }

    if (visited[node->val] != NULL) {
        return visited[node->val];
    }

    struct Node* cloned_node = (struct Node*)malloc(sizeof(struct Node));
    cloned_node->val = node->val;
    cloned_node->numNeighbors = node->numNeighbors;
    
    if (node->numNeighbors > 0) {
        cloned_node->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);
    } else {
        cloned_node->neighbors = NULL;
    }

    visited[node->val] = cloned_node;

    for (int i = 0; i < node->numNeighbors; i++) {
        cloned_node->neighbors[i] = dfs_clone(node->neighbors[i], visited);
    }

    return cloned_node;
}

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) {
        return NULL;
    }

    struct Node** visited = (struct Node**)calloc(101, sizeof(struct Node*));
    
    struct Node* result = dfs_clone(s, visited);
    
    free(visited);
    
    return result;
}
