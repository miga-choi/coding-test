import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;
import java.util.stream.Collectors;

class NextGreaterElementI {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        List<Integer> result = new ArrayList<Integer>();
        List<Integer> nums2List = Arrays.stream(nums2).boxed().collect(Collectors.toList());
        for (int i = 0; i < nums1.length; i++) {
            final int num = nums1[i];
            int index = nums2List.indexOf(num);
            if (index >= 0) {
                List<Integer> newNums2List = nums2List.subList(index + 1, nums2List.size()).stream().filter(t -> t > num).toList();
                if (newNums2List.size() > 0) {
                    result.add(newNums2List.get(0));
                } else {
                    result.add(-1);
                }
            } else {
                result.add(-1);
            }
        }
        return result.stream().mapToInt(v -> v).toArray();
    }


    // Best Solution
    public int[] bestSolution(int[] nums1, int[] nums2) {
        // map from x to next greater element of x
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        Stack<Integer> stack = new Stack<Integer>();
        for (int num : nums2) {
            while (!stack.isEmpty() && stack.peek() < num) {
                map.put(stack.pop(), num);
            }
            stack.push(num);
        }
        for (int i = 0; i < nums1.length; i++) {
            nums1[i] = map.getOrDefault(nums1[i], -1);
        }
        return nums1;
    }
}