#include <limits.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * list1Size);
    int intArray[list1Size];

    for (int i = 0; i < list1Size; i++) {
        intArray[i] = list1Size + list2Size;
    }

    int minIndex = list1Size + list2Size;

    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                int indexSum = i + j;
                intArray[i] = indexSum;
                if (indexSum <= minIndex) {
                    minIndex = indexSum;
                }
            }
        }
    }

    *returnSize = 0;
    for (int i = 0; i < list1Size; i++) {
        if (intArray[i] == minIndex) {
            result[(*returnSize)++] = list1[i];
        }
    }

    return result;
}

// Solution
char** solution(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    char** arr = (char**)malloc((list1Size+list2Size) * sizeof(char*));
    *returnSize = 0;
    int min = INT_MAX;
    for (int i=0 ; i<list1Size ; i++){
        for (int j=0 ; j<list2Size ; j++){
            if(strcmp(list1[i], list2[j]) == 0){
                int indexsum;
                indexsum = i+j;
                if(indexsum < min){
                    min = indexsum;
                    *returnSize = 0;
                    arr[*returnSize] = list1[i];
                    (*returnSize)++;
                }else if(indexsum == min){
                    arr[*returnSize] = list1[i];
                    (*returnSize)++;
                }
            }
        }
    }
    arr = (char**)realloc(arr, (*returnSize) * sizeof(char*));
    return arr;
}
