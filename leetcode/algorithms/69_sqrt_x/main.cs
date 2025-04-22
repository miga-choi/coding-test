public class SqrtX {
    public int MySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        int low = 1;
        int high = x;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return high;
    }


    // Solution
    // Solution 1
    public int solution1(int x) {
        int first = 0, last = x;
        while (first <= last) {
            long mid = (first + last) / 2, temp = mid * mid;
            if (x == temp) {
                return (int)mid;
            } else if (temp > x) {
                last = (int)(mid - 1);
            } else {
                first = (int)(mid + 1);
            }
        }
        return last;
    }

    // Solution 2
    public int solution2(int x) {
        if (x == 0) {
            return 0;
        }

        int left = 1;
        int right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sqrt = x / mid;

            if (sqrt == mid) {
                return mid;
            } else if (sqrt < mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }

    // Solution 3
    public int solution3(int x) {
        if (x == 1) {
            return x;
        }
        for (double i = 0; i <= x; i++) {
            if (i * i > x) {
                return Convert.ToInt32(i - 1);
            }
        }
        return 0;
    }
}
