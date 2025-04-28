import java.util.Arrays;

class AssignCookies {
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
    public int solution(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int i = 0;
        for (int j = 0; i < g.length && j < s.length; j++) {
            if (g[i] <= s[j]) {
                i++;
            }
        }

        return i;
    }
}
