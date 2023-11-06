import java.util.Arrays;
import java.util.Collections;

class RelativeRanks {
    public String[] findRelativeRanks(int[] score) {
        String[] result = new String[score.length];
        Integer[] sortedScore = Arrays.stream(score).boxed().toArray(Integer[]::new).clone();
        Arrays.sort(sortedScore, Collections.reverseOrder());
        for (int i = 0; i < score.length; i++) {
            switch (Arrays.asList(sortedScore).indexOf(score[i])) {
                case 0:
                    result[i] = "Gold Medal";
                    break;
                case 1:
                    result[i] = "Silver Medal";
                    break;
                case 2:
                    result[i] = "Bronze Medal";
                    break;
                default:
                    result[i] = String.valueOf(Arrays.asList(sortedScore).indexOf(score[i]) + 1);
                    break;
            }
        }
        return result;
    }


    // Best Solution
    /*
     * Example:
     * 
     * nums[i] : [10, 3, 8, 9, 4]
     * pair[i][0] : [10, 3, 8, 9, 4]
     * pair[i][1] : [ 0, 1, 2, 3, 4]
     * 
     * After sort:
     * pair[i][0] : [10, 9, 8, 4, 3]
     * pair[i][1] : [ 0, 3, 2, 4, 1]
     */
    public String[] bestSolution1(int[] score) {
        int[][] pair = new int[score.length][2];

        for (int i = 0; i < score.length; i++) {
            pair[i][0] = score[i];
            pair[i][1] = i;
        }

        Arrays.sort(pair, (a, b) -> (b[0] - a[0]));

        String[] result = new String[score.length];

        for (int i = 0; i < score.length; i++) {
            if (i == 0) {
                result[pair[i][1]] = "Gold Medal";
            } else if (i == 1) {
                result[pair[i][1]] = "Silver Medal";
            } else if (i == 2) {
                result[pair[i][1]] = "Bronze Medal";
            } else {
                result[pair[i][1]] = (i + 1) + "";
            }
        }

        return result;
    }

    // Dimension array
    public String[] bestSolution2(int[] score) {
        Integer[] index = new Integer[score.length];

        for (int i = 0; i < score.length; i++) {
            index[i] = i;
        }

        Arrays.sort(index, (a, b) -> (score[b] - score[a]));

        String[] result = new String[score.length];

        for (int i = 0; i < score.length; i++) {
            if (i == 0) {
                result[index[i]] = "Gold Medal";
            } else if (i == 1) {
                result[index[i]] = "Silver Medal";
            } else if (i == 2) {
                result[index[i]] = "Bronze Medal";
            } else {
                result[index[i]] = (i + 1) + "";
            }
        }

        return result;
    }
}
