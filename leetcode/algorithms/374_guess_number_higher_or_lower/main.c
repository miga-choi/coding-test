/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

int guessNumber(int n) {
    int low = 1;
    int high = n;
    int mid;
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (guess(mid) == -1) {
            high = mid - 1;
        } else if (guess(mid) == 1) {
            low = mid + 1;
        } else if (guess(mid) == 0) {
            break;
        }
    }
    return mid;
}

int guessNumber(int n) {
    int lo = 1;
    int hi = n;
    while (lo < hi) {
        int mid = (hi - lo) / 2 + lo;
        if (guess(mid) == 1) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}
