#include <ctype.h>
#include <string.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
}


// Solution
int primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,  41, 43,
                47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

long getCharProduct(char* plate) {
    u_int64_t product = 1;

    for (int i = 0; plate[i] != '\0'; i++) {
        int index = plate[i] - 'a';

        if (0 <= index && index <= 25) {
            product *= primes[index];
        }
    }

    return product;
}

char* solution(char* licensePlate, char** words, int wordsSize) {
    for (int i = 0; licensePlate[i] != '\0'; i++) {
        licensePlate[i] = tolower(licensePlate[i]);
    }

    long charProduct = getCharProduct(licensePlate);
    char* shortest = "aaaaaaaaaaaaaaaaaaaa"; // 16 a's
    int shortestLength = 16;

    for (int i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) < shortestLength &&
            getCharProduct(words[i]) % charProduct == 0) {
            shortest = words[i];
            shortestLength = strlen(words[i]);
        }
    }

    return shortest;
}
