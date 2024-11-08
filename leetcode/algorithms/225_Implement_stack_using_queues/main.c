#include <stdlib.h>

typedef struct
{
    int *intArray;
    int topIndex;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *myStack = (MyStack *)malloc(sizeof(MyStack));
    myStack->intArray = (int *)malloc(sizeof(int) * 100);
    myStack->topIndex = -1;
    return myStack;
}

void myStackPush(MyStack *obj, int x)
{
    if (obj->topIndex < 99)
    {
        obj->topIndex++;
        obj->intArray[obj->topIndex] = x;
    }
}

int myStackPop(MyStack *obj)
{
    if (obj->topIndex < 0)
    {
        return -1;
    }
    return obj->intArray[obj->topIndex--];
}

int myStackTop(MyStack *obj)
{
    if (obj->topIndex < 0)
    {
        return -1;
    }
    return obj->intArray[obj->topIndex];
}

bool myStackEmpty(MyStack *obj)
{
    return obj->topIndex < 0;
}

void myStackFree(MyStack *obj)
{
    free(obj->intArray);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

// Best Solution
int size = 100;

typedef struct
{
    int *arr;
    int size;
    int top;
} BestSolution_MyStack;

BestSolution_MyStack *bestSolution_myStackCreate()
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->arr = (int *)malloc(size * sizeof(int));
    stack->size = size;
    stack->top = -1;
    return stack;
}

void bestSolution_myStackPush(MyStack *obj, int x)
{
    if (obj->top < obj->size - 1)
    {
        obj->top++;
        obj->arr[obj->top] = x;
    }
}

int bestSolution_myStackPop(MyStack *obj)
{
    if (obj->top == -1)
    {
        return -1;
    }
    return obj->arr[obj->top--];
}

int bestSolution_myStackTop(MyStack *obj)
{
    if (obj->top == -1)
    {
        return -1;
    }
    return obj->arr[obj->top];
}

bool bestSolution_myStackEmpty(MyStack *obj)
{
    return obj->top == -1;
}

void bestSolution_myStackFree(MyStack *obj)
{
    free(obj->arr);
    free(obj);
}
