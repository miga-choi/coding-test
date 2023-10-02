import java.util.Arrays;

class NumberOfSegmentsInAString {
    public int countSegments(String s) {
        return Arrays.stream(s.split(" ")).filter(v -> !v.equals("")).toArray().length;
    }


    // Best Solution
    public int bestSolution1(String s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != ' ' && (i == 0 || s.charAt(i - 1) == ' ')) {
                res++;
            }
        }
        return res;
    }

    public int bestSolution2(String s) {
        return ("x " + s).split(" +").length - 1;
    }
}