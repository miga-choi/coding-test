#include <stdlib.h>

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/

typedef struct {
    int* nums;
} MyHashMap;

MyHashMap* myHashMapCreate() {
    MyHashMap* myHashMap = (MyHashMap*)malloc(sizeof(MyHashMap));

    myHashMap->nums = (int*)malloc(sizeof(int) * (1e6 + 1));
    for (int i = 0; i < (1e6 + 1); i++) {
        myHashMap->nums[i] = -1;
    }

    return myHashMap;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->nums[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->nums[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->nums[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj);
}


// Solution
typedef struct {
    int* ans;
} Solution_MyHashMap;

Solution_MyHashMap* myHashMapCreate() {
    Solution_MyHashMap* obj = (Solution_MyHashMap*)malloc(sizeof(Solution_MyHashMap));
    obj->ans = (int*)malloc(1000001 * sizeof(int));
    for (int i = 0; i < 1000001; i++) {
        obj->ans[i] = -1;
    }
    return obj;
}

void myHashMapPut(Solution_MyHashMap* obj, int key, int value) {
    obj->ans[key] = value;
}

int myHashMapGet(Solution_MyHashMap* obj, int key) {
    return obj->ans[key];
}

void myHashMapRemove(Solution_MyHashMap* obj, int key) {
    obj->ans[key] = -1;
}

void myHashMapFree(Solution_MyHashMap* obj) {
    free(obj->ans);
    free(obj);
}
