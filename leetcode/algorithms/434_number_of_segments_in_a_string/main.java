import java.util.Arrays;

class NumberOfSegmentsInAString {
    public int countSegments(String s) {
        return Arrays.stream(s.split(" ")).filter(v -> !v.equals("")).toArray().length;
    }


    // Solution
    // Solution 1
    public int solution1(String s) {
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != ' ' && (i == 0 || s.charAt(i - 1) == ' ')) {
                res++;
            }
        }

        return res;
    }

    // Solution 2
    public int solution2(String s) {
        return ("x " + s).split(" +").length - 1;
    }
}