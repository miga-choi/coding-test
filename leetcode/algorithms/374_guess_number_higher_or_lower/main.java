/**
 * Forward declaration of guess API.
 * 
 * @param num your guess
 * @return -1 if num is higher than the picked number
 *         1 if num is lower than the picked number
 *         otherwise return 0
 * 
 *         int guess(int num);
 */

class GuessGame {
    int guess(int num) {
        return 0;
    }
}

class GuessNumberHigherOrLower extends GuessGame {
    public int guessNumber(int n) {
        long left = 0;
        long right = n;
        long mid = n / 2;

        while (left <= right) {
            mid = (left + right) / 2;
            if (super.guess(Long.valueOf(mid).intValue()) > 0) {
                left = mid + 1;
            } else if (super.guess(Long.valueOf(mid).intValue()) < 0) {
                right = mid - 1;
            } else {
                break;
            }

        }

        return Long.valueOf(mid).intValue();
    }


    // Best Solution
    public int bestSolution(int n) {
        long start = 1, end = n, mid;
        while (start <= end) {

            mid = (start + end) / 2;

            if (guess((int) mid) == 0)
                return (int) mid;
            else if (guess((int) mid) == 1)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }
}
