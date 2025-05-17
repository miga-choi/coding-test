#include <stdbool.h>
#include <stdlib.h>

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/

typedef struct {
    int* nums;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* myHashSet = (MyHashSet*)malloc(sizeof(MyHashSet));
    myHashSet->nums = (int*)calloc(1000001, sizeof(int));
    return myHashSet;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->nums[key] = 1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->nums[key] = 0;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->nums[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}


// Solution
#define TBL_SIZE 500

struct MyListNode {
    struct MyListNode* next;
    int val;
};

typedef struct {
    struct MyListNode* tbl[TBL_SIZE];
} Solution_MyHashSet;

/** Initialize your data structure here. */
Solution_MyHashSet* solution_myHashSetCreate() {
    Solution_MyHashSet* p = (Solution_MyHashSet*)malloc(sizeof(Solution_MyHashSet));
    if (p) {
        memset(p, 0, sizeof(Solution_MyHashSet));
    }
    return p;
}

void solution_myHashSetAdd(Solution_MyHashSet* obj, int key) {
    int idx = key % TBL_SIZE;
    struct MyListNode** addedNode;
    struct MyListNode* node = obj->tbl[idx];
    if (!node) {
        addedNode = &obj->tbl[idx];
    } else {
        while (node) {
            if (node->val == key)
                return;
            if (!node->next) {
                addedNode = &node->next;
                break;
            }
            node = node->next;
        }
    }
    *addedNode = (struct MyListNode*)malloc(sizeof(struct MyListNode));
    (*addedNode)->val = key;
    (*addedNode)->next = NULL;
}

void solution_myHashSetRemove(Solution_MyHashSet* obj, int key) {
    int idx = key % TBL_SIZE;
    struct MyListNode* node = obj->tbl[idx];
    struct MyListNode* t;
    if (node && node->val == key) {
        obj->tbl[idx] = node->next;
        free(node);
    } else {
        while (node) {
            if (node->next && node->next->val == key) {
                t = node->next;
                node->next = t->next;
                free(t);
                break;
            }
            node = node->next;
        }
    }
}

/** Returns true if this set contains the specified element */
bool solution_myHashSetContains(Solution_MyHashSet* obj, int key) {
    int idx = key % TBL_SIZE;
    struct MyListNode* node = obj->tbl[idx];
    while (node) {
        if (node->val == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}

void solution_myHashSetFree(Solution_MyHashSet* obj) {
    int i;
    struct MyListNode *node, *t;
    for (i = 0; i < TBL_SIZE; i++) {
        node = obj->tbl[i];
        while (node) {
            t = node->next;
            free(node);
            node = t;
        }
    }
    free(obj);
}
