class ValidPerfectSquare {
public:
    bool isPerfectSquare(int num) {
        if (num > 1) {
            for (long i = 0; i < num; i++) {
                if (i * i == num) {
                    break;
                } else if (i * i > num) {
                    return false;
                }
            }
        }
        return true;
    }

    // Best Solution
    bool bestSolution(int num) {
        long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        return r * r == x;
    }
};
