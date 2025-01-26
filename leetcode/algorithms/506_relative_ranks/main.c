#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * scoreSize);
    int* sortedScore = (int*)malloc(sizeof(int) * scoreSize);
    memcpy(sortedScore, score, sizeof(int) * scoreSize);

    for (int i = 0; i < scoreSize - 1; i++) {
        for (int j = i + 1; j < scoreSize; j++) {
            if (sortedScore[i] < sortedScore[j]) {
                int temp = sortedScore[i];
                sortedScore[i] = sortedScore[j];
                sortedScore[j] = temp;
            }
        }
    }

    for (int i = 0; i < scoreSize; i++) {
        if (score[i] == sortedScore[0]) {
            result[i] = "Gold Medal";
        } else if (score[i] == sortedScore[1]) {
            result[i] = "Silver Medal";
        } else if (score[i] == sortedScore[2]) {
            result[i] = "Bronze Medal";
        } else {
            for (int j = 3; j < scoreSize; j++) {
                if (score[i] == sortedScore[j]) {
                    result[i] = (char*)malloc(sizeof(char) * 6);
                    sprintf(result[i], "%d", j + 1);
                }
            }
        }
    }

    *returnSize = scoreSize;
    return result;
}

// Solution
int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int binSearch(int* a, int n, int val) {
    int lo = 0, mid, hi = n - 1;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (a[mid] == val) {
            break;
        }
        if (a[mid] < val) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return mid;
}

char** solution(int* score, int scoreSize, int* returnSize) {
    int i, rank, ranks[scoreSize];
    char** placements = (char**)malloc(scoreSize * sizeof(char*));
    memcpy(ranks, score, sizeof(ranks));
    qsort(ranks, scoreSize, sizeof(int), compare);
    for (i = 0; i < scoreSize; ++i) {
        rank = binSearch(ranks, scoreSize, score[i]);
        switch (rank) {
        case 0:
            placements[i] = strdup("Gold Medal");
            break;
        case 1:
            placements[i] = strdup("Silver Medal");
            break;
        case 2:
            placements[i] = strdup("Bronze Medal");
            break;
        default:
            placements[i] = (char*)malloc(6 * sizeof(char));
            sprintf(placements[i], "%d", rank + 1);
        }
    }
    *returnSize = scoreSize;
    return placements;
}
