int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }

    long low = 1;
    long high = x;

    while (low <= high) {
        long mid = (low + high) / 2;

        if (mid == x / mid) {
            return (int)mid;
        } else if (mid > x / mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)high;
}


// Solution
// Solution 1:
int solution1(int x) {
    long r = x;
    while (r * r > x) {
        r = (r + x / r) / 2;
    }
    return r;
}

// Solution 2:
int solution2(int x) {
    // long long due to some of test cases overflows integer limit.
    long long s = 0, e = x, ans, mid;

    while (s <= e) {
        mid = (s + e) / 2;
        if (mid * mid == x) {
            // if the 'mid' value ever gives the result, we simply return it.
            return mid; 
        } else if (mid * mid < x) {
            // if 'mid' value encounterted gives lower result, we simply discard all the values lower than mid.
            s = mid + 1;
            // an extra pointer 'ans' is maintained to keep track of only lowest 'mid' value.
            ans = mid;
        } else {
            // if 'mid' value encountered gives greater result, we simply discard all the values greater than mid.
            e = mid - 1;
        }
    }
    return ans;
}

// Solution 3:
int solution3(int x) {
    long long i = 0;
    while (i * i <= x) {
        i++;
    }
    return i - 1;
}
