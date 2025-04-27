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


    // Solution
    bool solution(int num) {
        long r = num;
        while (r * r > num) {
            r = (r + num / r) / 2;
        }
        return r * r == num;
    }
};
