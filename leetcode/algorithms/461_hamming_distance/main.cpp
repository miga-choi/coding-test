class HammingDistance {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0, n = x ^ y;
        while (n) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }

    // Best Solution
    int bestSolution(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};
