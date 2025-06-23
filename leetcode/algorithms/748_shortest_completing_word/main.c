#include <ctype.h>
#include <string.h>

int isCompleting(int* plateFreq, char* word) {
    int wordFreq[26] = {0};

    for (int i = 0; word[i] != '\0'; i++) {
        wordFreq[word[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (wordFreq[i] < plateFreq[i]) {
            return 0;
        }
    }

    return 1;
}

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int plateFreq[26] = {0};

    for (int i = 0; licensePlate[i] != '\0'; i++) {
        if (isalpha(licensePlate[i])) {
            plateFreq[tolower(licensePlate[i]) - 'a']++;
        }
    }

    char* shortestWord = NULL;
    int minLength = 15;

    for (int i = 0; i < wordsSize; i++) {
        int currentLength = strlen(words[i]);

        if (currentLength >= minLength) {
            continue;
        }

        if (isCompleting(plateFreq, words[i])) {
            minLength = currentLength;
            shortestWord = words[i];
        }
    }

    return shortestWord;
}


// Solution
int primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

unsigned long getCharProduct(char* plate) {
    unsigned long product = 1L;

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
