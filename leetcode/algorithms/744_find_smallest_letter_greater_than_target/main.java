class FindSmallestLetterGreaterThanTarget {
    public char nextGreatestLetter(char[] letters, char target) {
        if (letters[letters.length - 1] <= target) {
            return letters[0];
        }

        for (int i = 0; i < letters.length; i++) {
            if (letters[i] > target) {
                return letters[i];
            }
        }

        return letters[0];
    }


    // Solution
    public char solution(char[] letters, char target) {
        int n = letters.length;

        // hi starts at 'n' rather than the usual 'n - 1'.
        // It is because the terminal condition is 'lo < hi'
        // and if hi starts from 'n - 1',
        // we can never consider value at index 'n - 1'.
        int lo = 0, hi = n;

        // Terminal condition is 'lo < hi', to avoid infinite loop
        // when target is smaller than the first element.
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (letters[mid] > target) {
                hi = mid;
            } else {
                // letters[mid] <= x.
                lo = mid + 1;
            }
        }

        // Because lo can end up pointing to index 'n',
        // in which case we return the first element.
        return letters[lo % n];
    }
}
