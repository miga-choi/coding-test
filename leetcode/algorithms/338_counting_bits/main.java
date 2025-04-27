import java.util.ArrayList;
import java.util.List;

class CountingBits {
    public int[] countBits(int n) {
        List<Integer> result = new ArrayList<Integer>();

        for (int i = 0; i <= n; i++) {
            int sum = 0;
            String bits = Integer.toBinaryString(i);
            for (int j = 0; j < bits.length(); j++) {
                sum += Integer.valueOf(String.valueOf(bits.charAt(j)));
            }
            result.add(sum);
        }

        return result.stream().mapToInt(value -> value).toArray();
    }


    // Solution
    public int[] solution(int num) {
        int[] f = new int[num + 1];

        for (int i = 1; i <= num; i++) {
            f[i] = f[i >> 1] + (i & 1);
        }

        return f;
    }
}
