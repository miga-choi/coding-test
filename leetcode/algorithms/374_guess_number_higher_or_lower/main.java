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
    /**
     * Binary Search
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
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


    // Solution
    /**
     * Solution 1
     * 
     * Binary Search
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    public int solution1(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);

            if (res == 0) {
                return mid;
            } else if (res == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    /**
     * Solution 2
     *
     * Recursion
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(logᴺ)
     */
    private int search(int left, int right) {
        int mid = left + (right - left) / 2;
        int res = guess(mid);

        if (res == 0) {
            return mid;
        }

        if (res == -1) {
            return search(left, mid - 1);
        }

        return search(mid + 1, right);
    }

    public int solution2(int n) {
        return search(1, n);
    }
}
