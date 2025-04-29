int countBinarySubstrings(char* s) {
    int count = 1;
    int prevCount = 0;
    int result = 0;

    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            if (count < prevCount) {
                result += count;
            } else {
                result += prevCount;
            }
            prevCount = count;
            count = 1;
        }
    }

    if (count < prevCount) {
        result += count;
    } else {
        result += prevCount;
    }

    return result;
}


// Solution
int solution(char* s) {
    int cur = 1, pre = 0, res = 0;

    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            cur++;
        } else {
            if (cur < pre) {
                res += cur;
            } else {
                res += pre;
            }
            pre = cur;
            cur = 1;
        }
    }

    if (cur < pre) {
        res += cur;
    } else {
        res += pre;
    }

    return res;
}
