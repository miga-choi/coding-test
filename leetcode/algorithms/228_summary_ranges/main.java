import java.util.ArrayList;
import java.util.List;

class SummaryRanges {
    public List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<String>();

        if (nums.length > 0) {
            int num = nums[0];
            List<Integer> numArray = new ArrayList<Integer>();
            numArray.add(num);

            for (int i = 1; i < nums.length; i++) {
                if (nums[i] - num == 1) {
                    numArray.add(nums[i]);
                } else {
                    if (numArray.size() > 1) {
                        result.add(String.valueOf(numArray.get(0)) + "->"
                                + String.valueOf(numArray.get(numArray.size() - 1)));
                    } else {
                        result.add(String.valueOf(numArray.get(0)));
                    }
                    numArray = new ArrayList<Integer>();
                    numArray.add(nums[i]);
                }
                num = nums[i];
            }

            if (numArray.size() > 0) {
                if (numArray.size() > 1) {
                    result.add(String.valueOf(numArray.get(0)) + "->"
                            + String.valueOf(numArray.get(numArray.size() - 1)));
                } else {
                    result.add(String.valueOf(numArray.get(0)));
                }
            }
        }

        return result;
    }


    // Best Solution
    /**
     * Question is saying wherever you are finding continous elements then keep them
     * in an interval
     * else keep them alone
     * 
     * EX-> [0,1,2,4,5,7]
     *      [0,1,2]-->[0->2] {2-4 in array is breakpoint}
     *      [4,5] -->[4->5]
     *      [7] -->[7]
     * 
     * Approach
     * 
     * Traverse the entire array
     *     1. keep start at every element and check whether i doesnt reached end and the
     *        ith element added with 1 gives the next element. If so then keep travelling
     *        ahead by incrementing i until you find a breakpoint
     *     2. Once you find a breakpoint where nums[i]+1!=nums[i+1],so at that time
     *        check whether nums[i]!=start,if so add it to list start+"->"+nums[i]
     *     3. else add just the start
     */
    public List<String> bestSolution(int[] nums) {
        ArrayList<String> al = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            int start = nums[i];
            while (i + 1 < nums.length && nums[i] + 1 == nums[i + 1])
                i++;

            if (start != nums[i]) {
                al.add("" + start + "->" + nums[i]);
            } else {
                al.add("" + start);
            }
        }
        return al;
    }
}