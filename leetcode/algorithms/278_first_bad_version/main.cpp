class FirstBadVersion {
public:
    // The API isBadVersion is defined for you.
    bool isBadVersion(int version);

    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid;
        while (low < high) {
            mid = low + ((high - low) / 2);
            if (isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }


    // Solution
    int solution(int n) {
        int start = 0, end = n;
        while (end - start > 1) {
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return end;
    }
};
