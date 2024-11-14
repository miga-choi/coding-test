typedef struct
{

} MyQueue;

MyQueue *myQueueCreate()
{
}

void myQueuePush(MyQueue *obj, int x)
{
}

int myQueuePop(MyQueue *obj)
{
}

int myQueuePeek(MyQueue *obj)
{
}

bool myQueueEmpty(MyQueue *obj)
{
}

void myQueueFree(MyQueue *obj)
{
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

// Best Solution
typedef struct
{
    int ar[100];
    int head;
    int tail;
    int cnt;
} BestSolution_MyQueue;

BestSolution_MyQueue *bestSolution_myQueueCreate()
{
    BestSolution_MyQueue *obj = malloc(sizeof(BestSolution_MyQueue));
    obj->head = 0;
    obj->tail = 0;
    obj->cnt = 0;
    return obj;
}

void bestSolution_myQueuePush(BestSolution_MyQueue *obj, int x)
{
    if (obj == NULL)
        return;

    obj->cnt++;
    obj->ar[obj->tail] = x;
    obj->tail = (obj->tail + 1) % 100;
}

int bestSolution_myQueuePop(BestSolution_MyQueue *obj)
{
    if (obj == NULL)
        return NULL;

    obj->cnt--;
    obj->head = (obj->head + 1) % 100;
    return (obj->ar[(obj->head - 1) % 100]);
}

int bestSolution_myQueuePeek(BestSolution_MyQueue *obj)
{
    if (obj == NULL)
        return NULL;

    return obj->ar[obj->head];
}

bool bestSolution_myQueueEmpty(BestSolution_MyQueue *obj)
{
    if (obj == NULL)
        return false;

    return (obj->cnt ? false : true);
}

void bestSolution_myQueueFree(BestSolution_MyQueue *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
