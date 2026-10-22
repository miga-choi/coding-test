import java.util.Arrays;

class AssignCookies {
    /**
     * Sorting + Greedy
     * 
     * Complexities:
     *   N - `gSize`
     *   M - `sSize`
     *   - Time Complexity: O(N * logᴺ + M * logᴹ)
     *   - Space Complexity: O(1)
     */
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int gi = 0;
        for (int sv : s) {
            if (gi >= g.length) {
                break;
            }
            if (sv >= g[gi]) {
                gi++;
            }
        }

        return gi;
    }


    // Solution
    /**
     * Sorting + Greedy
     * 
     * Complexities:
     *   N - `gSize`
     *   M - `sSize`
     *   - Time Complexity: O(N * logᴺ + M * logᴹ)
     *   - Space Complexity: O(1)
     */
    public int solution(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int i = 0, j = 0;
        while (i < g.length && j < s.length) {
            if (s[j] >= g[i]) {
                i++;
            }
            j++;
        }

        return i;
    }
}
