int hammingDistance(int x, int y) {
    int cnt = 0;
    while (x || y) {
        if (x % 2 != y % 2) {
            cnt++;
        }
        x /= 2;
        y /= 2;
    }
    return cnt;
}


// Solution
int solution(int x, int y) {
    int dist = 0, n = x ^ y;
    while (n) {
        ++dist;
        n &= n - 1;
    }
    return dist;
}
