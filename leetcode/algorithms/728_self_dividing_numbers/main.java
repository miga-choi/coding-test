
import java.util.ArrayList;
import java.util.List;

class SelfDividingNumbers {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> result = new ArrayList<>();

        for (int i = left; i <= right; i++) {
            int v = i;

            while (v > 0) {
                if (v % 10 == 0 || i % (v % 10) > 0) {
                    break;
                }

                v /= 10;
            }

            if (v == 0) {
                result.add(i);
            }
        }

        return result;
    }


    // Solution
    public List<Integer> solution(int left, int right) {
        List<Integer> res = new ArrayList<>();

        for (int i = left, n = 0; i <= right; i++) {
            for (n = i; n > 0; n /= 10) {
                if (n % 10 == 0 || i % (n % 10) != 0) {
                    break;
                }
            }

            if (n == 0) {
                res.add(i);
            }
        }

        return res;
    }
}
