void reverseString(char *s, int sSize) {
    for (int i = 0; i < sSize / 2; i++) {
        char temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
}


// Solution
void solution(char *s, int sSize) {
    int i = 0;
    int j = sSize - 1;

    while (i <= j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}
