class AddDigits {
public:
    int addDigits(int num) {
        int sum = num;
        while (sum >= 10) {
            sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return sum;
    }


    // Solution
    int solution(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        if (sum < 10) {
            return sum;
        } else {
            return addDigits(sum);
        }
    }
};
