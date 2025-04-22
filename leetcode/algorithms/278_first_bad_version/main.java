/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */
class VersionControl {
    boolean isBadVersion(int version) {
        return false;
    }
}

class FirstBadVersion extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 0;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }


    // Solution
    // Solution 1: First Bad Version Left
    public int solution1(int n) {
        int i = 1;
        int j = n;

        while (i < j) {
            int mid = i + (j - i) / 2;

            if (isBadVersion(mid)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }

        return i;
    }

    // Solution 2: First Bad Version Right
    public int solution2(int n) {
        if (isBadVersion(1)) {
            return 1;
        }

        int i = 1;
        int j = n;

        while (i < j) {
            int mid = i + (j - i) / 2 + 1;
            if (!isBadVersion(mid)) {
                i = mid;
            } else {
                j = mid - 1;
            }
        }

        return j + 1;
    }
}
