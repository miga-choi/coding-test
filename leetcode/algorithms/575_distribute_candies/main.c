int distributeCandies(int* candyType, int candyTypeSize) {
    int candyTypeArray[200001] = {0};
    int candyTypeCount = 0;

    for (int i = 0; i < candyTypeSize; i++) {
        if (!candyTypeArray[candyType[i] + 100000]) {
            candyTypeArray[candyType[i] + 100000] = 1;
            candyTypeCount++;
        }
    }

    return candyTypeCount < candyTypeSize / 2 ? candyTypeCount : candyTypeSize / 2;
}

// Solution
int cmp_func(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int solution(int* candyType, int candyTypeSize) {
    int different_candy_cnt = 1;
    int edible_candies = candyTypeSize / 2;

    qsort(candyType, candyTypeSize, sizeof(int), cmp_func);

    for (int i = 0, j = 0; j < candyTypeSize; j++) {
        if (candyType[i] != candyType[j]) {
            i = j;
            different_candy_cnt++;
        }
    }

    return (edible_candies > different_candy_cnt) ? different_candy_cnt : edible_candies;
}
