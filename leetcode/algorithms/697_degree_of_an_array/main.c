#include <stdlib.h>
#include <string.h>

int findShortestSubArray(int* nums, int numsSize) {
    struct NumStruct {
        int left;
        int right;
        int count;
    };

    struct NumStruct numStruct[50000];
    memset(numStruct, -1, sizeof(numStruct));

    int maxCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (numStruct[nums[i]].left == -1) {
            numStruct[nums[i]].left = i;
        }
        numStruct[nums[i]].right = i;
        numStruct[nums[i]].count++;
        if (numStruct[nums[i]].count > maxCount) {
            maxCount = numStruct[nums[i]].count;
        }
    }

    int minSubarrayLength = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (numStruct[nums[i]].count == maxCount) {
            int length = numStruct[nums[i]].right - numStruct[nums[i]].left;
            if (length < minSubarrayLength) {
                minSubarrayLength = length;
            }
        }
    }

    return minSubarrayLength + 1;
}


// Solution
int findShortestSubArray(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    // 1) 값의 최대범위(M)를 구해서 동적 배열 크기 결정
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    int M = maxVal + 1;
    
    // 2) left[]는 -1로 초기화, count[]는 0으로
    int* left = malloc(M * sizeof *left);
    int* count = calloc(M, sizeof *count);

    for (int v = 0; v < M; v++) {
        left[v] = -1;
    }
    
    int degree = 0;
    int minLen = numsSize;
    
    // 3) 한 번 순회하며
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
    
        // 첫 등장 기록
        if (left[v] == -1) {
            left[v] = i;
        }
    
        // 빈도 증가
        count[v]++;
    
        // 새로 갱신된 빈도가 최대치라면
        if (count[v] > degree) {
            degree = count[v];
            minLen = i - left[v] + 1;
        }
        // 빈도가 기존 최대치와 같다면 길이 비교
        else if (count[v] == degree) {
            int len = i - left[v] + 1;
            if (len < minLen) {
                minLen = len;
            }
        }
    }
    
    free(left);
    free(count);
    return minLen;
}
