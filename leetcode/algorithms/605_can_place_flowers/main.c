#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (flowerbedSize == 1) {
        return flowerbed[0] == 0 || n == 0;
    }
    for (int i = 0; i < flowerbedSize && n > 0; i++) {
        if (i == 0) {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        } else if (i == flowerbedSize - 1) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        } else {
            if (flowerbed[i - 1] == 0 &&
                flowerbed[i] == 0 &&
                flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
    }
    return n == 0;
}

// Solution
bool solution(int* flowerbed, int flowerbedSize, int n) {
    if (n == 0) {
        return true;
    }
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
            (i == flowerbedSize - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            n--;
            if (n == 0) {
                return true;
            }
        }
    }
    return false;
}
