#include <stdbool.h>
#include <stdlib.h>

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
*/

typedef struct {
    int* input;
    int* output;
    int inputIndex;
    int outputIndex;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* myQueue = (MyQueue*)malloc(1 * sizeof(MyQueue));

    myQueue->input = (int*)malloc(100 * sizeof(int));
    myQueue->output = (int*)malloc(100 * sizeof(int));
    myQueue->inputIndex = -1;
    myQueue->outputIndex = -1;

    return myQueue;
}

// Pushes element x to the back of the queue.
void myQueuePush(MyQueue* obj, int x) {
    obj->inputIndex++;
    obj->input[obj->inputIndex] = x;
}

// Removes the element from the front of the queue and returns it.
int myQueuePop(MyQueue* obj) {
    int front = myQueuePeek(obj);

    if (front != -1) {
        obj->outputIndex--;
    }

    return front;
}

// Returns the element at the front of the queue.
int myQueuePeek(MyQueue* obj) {
    if (obj->outputIndex < 0) {
        while (obj->inputIndex >= 0) {
            obj->outputIndex++;
            obj->output[obj->outputIndex] = obj->input[obj->inputIndex];
            obj->inputIndex--;
        }
    }

    return obj->outputIndex < 0 ? -1 : obj->output[obj->outputIndex];
}

// Returns true if the queue is empty, false otherwise.
bool myQueueEmpty(MyQueue* obj) {
    return obj->inputIndex == -1 && obj->outputIndex == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->input);
    free(obj->output);
    free(obj);
}


// Solution
typedef struct {
    int ar[100];
    int head;
    int tail;
    int cnt;
} Solution1_MyQueue;

Solution1_MyQueue* solution1_myQueueCreate() {
    Solution1_MyQueue* obj = malloc(sizeof(Solution1_MyQueue));
    obj->head = 0;
    obj->tail = 0;
    obj->cnt = 0;
    return obj;
}

void solution1_myQueuePush(Solution1_MyQueue* obj, int x) {
    if (obj == NULL) {
        return;
    }

    obj->cnt++;
    obj->ar[obj->tail] = x;
    obj->tail = (obj->tail + 1) % 100;
}

int solution1_myQueuePop(Solution1_MyQueue* obj) {
    if (obj == NULL) {
        return NULL;
    }

    obj->cnt--;
    obj->head = (obj->head + 1) % 100;
    return (obj->ar[(obj->head - 1) % 100]);
}

int solution1_myQueuePeek(Solution1_MyQueue* obj) {
    if (obj == NULL) {
        return NULL;
    }

    return obj->ar[obj->head];
}

bool solution1_myQueueEmpty(Solution1_MyQueue* obj) {
    if (obj == NULL) {
        return false;
    }

    return (obj->cnt ? false : true);
}

void solution1_myQueueFree(Solution1_MyQueue* obj) {
    if (obj == NULL) {
        return;
    }
    free(obj);
}

// Solution 2
#define MAX_CALL 100

typedef struct {
    int* in;     // Keep add new element into stack `in`
    int* out;    // While `out` is not empty the peek of the queue is the top of `out`
    int idx_in;  // Pointer points to the last element of array in
    int idx_out; // Pointer points to the last element of array out
} Solution2_MyQueue;

Solution2_MyQueue* solution2_myQueueCreate() {
    Solution2_MyQueue* queue = (Solution2_MyQueue*)malloc(sizeof(Solution2_MyQueue));

    if (queue == NULL) {
        return NULL;
    }

    queue->in = (int*)malloc(MAX_CALL * sizeof(int));
    queue->out = (int*)malloc(MAX_CALL * sizeof(int));
    queue->idx_in = -1;
    queue->idx_out = -1;

    return queue;
}

void solution2_myQueuePush(Solution2_MyQueue* obj, int x) {
    obj->in[++obj->idx_in] = x;
}

int solution2_myQueuePop(Solution2_MyQueue* obj) {
    int front = solution2_myQueuePeek(obj);

    if (front != -1) {
        obj->idx_out--;
    }

    return front;
}

int solution2_myQueuePeek(Solution2_MyQueue* obj) {
    /* Find fill the out if it's empty */
    if (obj->idx_out < 0) {
        while (obj->idx_in >= 0) {
            obj->out[++obj->idx_out] = obj->in[obj->idx_in--];
        }
    }

    return obj->idx_out < 0 ? -1 : obj->out[obj->idx_out];
}

bool solution2_myQueueEmpty(Solution2_MyQueue* obj) {
    return obj->idx_in == -1 && obj->idx_out == -1;
}

void solution2_myQueueFree(Solution2_MyQueue* obj) {
    free(obj->in);
    free(obj->out);
    free(obj);
}
