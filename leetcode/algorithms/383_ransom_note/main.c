#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int alphabetMap[26] = {0};
    for (int i = 0; magazine[i] != '\0'; i++) {
        alphabetMap[magazine[i] - 'a']++;
    }
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (alphabetMap[ransomNote[i] - 'a'] > 0) {
            alphabetMap[ransomNote[i] - 'a']--;
        } else {
            return false;
        }
    }
    return true;
}

bool canConstruct(char* ransomNote, char* magazine) {
    // Initialize an array of count with the size 26...
    int counter[26] = {0};

    // Traverse a loop through the entire String of magazine where char ch
    // stores the char at the index of magazine...
    for (int i = 0; i < magazine[i] != '\0'; i++) {
        counter[magazine[i] - 'a']++;
    }

    // Run another for loop for ransomNote...
    for (int i = 0; i < ransomNote[i] != '\0'; i++) {
        // If the charachter doesn't exists in magazine for ransomNote, we
        // return false...
        if (counter[ransomNote[i] - 'a']-- <= 0) {
            return false;
        }
    }

    // If nothing goes wrong, return true...
    return true;
}
