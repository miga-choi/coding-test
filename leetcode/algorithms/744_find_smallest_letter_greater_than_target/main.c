char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int min = 'z' + 1;

    for (int i = 0; i < lettersSize; i++) {
        if (letters[i] > target &&  letters[i] < min) {
            min = letters[i];
        }
    }

    if (min == 'z' + 1) {
        return letters[0];
    }

    return min;
}


// Solution
char solution(char* letters, int lettersSize, char target) {
    if (letters[lettersSize - 1] <= target) {
        return letters[0];
    }

    int low = 0;
    int high = lettersSize - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (target < letters[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return letters[low];
}
