int numJewelsInStones(char* jewels, char* stones) {
    int numsArray[52] = {0};
    for (int i = 0; jewels[i] != '\0'; i++) {
        if (jewels[i] > 'Z') {
            numsArray[jewels[i] - 'a' + 26] = 1;
        } else {
            numsArray[jewels[i] - 'A'] = 1;
        }
    }

    int count = 0;
    for (int i = 0; stones[i] != '\0'; i++) {
        if (stones[i] > 'Z') {
            count += numsArray[stones[i] - 'a' + 26];
        } else {
            count += numsArray[stones[i] - 'A'];
        }
    }

    return count;
}


// Solution
int solution(char* jewels, char* stones) {
    char t[128] = {};
    for (char* p = jewels; *p; ++p) {
        t[*p] = (char)1;
    }
    
    int a = 0;
    for (char* p = stones; *p; ++p) {
        a = a + t[*p];
    }

    return a;
}
