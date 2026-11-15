class ConstructTheRectangle {
    /**
     * Divisor Search from Square Root
     * 
     * Complexities:
     *   n - `area`
     *   - Time Complexity: O(√n)
     *   - Space Complexity: O(1)
     */
    public int[] constructRectangle(int area) {
        int w = Double.valueOf(Math.sqrt(area)).intValue();

        while (area % w != 0) {
            w--;
        }

        int[] result = { area / w, w };

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Divisor Search from Square Root
     * 
     * Complexities:
     *   n - `area`
     *   - Time Complexity: O(√n)
     *   - Space Complexity: O(1)
     */
    public int[] solution1(int area) {
        int w = (int) Math.sqrt(area);

        while (area % w != 0) {
            w--;
        }

        return new int[] { area / w, w };
    }

    /**
     * Solution 2
     * 
     * Divisor Search from One (Ascending)
     * 
     * Complexities:
     *   n - `area`
     *   - Time Complexity: O(√n)
     *   - Space Complexity: O(1)
     */
    public int[] solution2(int area) {
        int w = 1;

        for (int i = 1; (long) i * i <= area; i++) {
            if (area % i == 0) {
                w = i;
            }
        }

        return new int[] { area / w, w };
    }
}
