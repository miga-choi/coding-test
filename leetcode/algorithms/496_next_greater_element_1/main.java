import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

class NextGreaterElementI {
    /**
     * Brute Force with Found Flag
     *
     * Complexities:
     *   n - The Size of `nums1`
     *   m - The Size of `nums2`
     *   - Time Complexity: O(n * m)
     *   - Space Complexity: O(1)
     */
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        List<Integer> result = new ArrayList<>();
        List<Integer> nums2List = Arrays.stream(nums2).boxed().collect(Collectors.toList());

        for (int i = 0; i < nums1.length; i++) {
            final int num = nums1[i];
            int index = nums2List.indexOf(num);

            if (index >= 0) {
                List<Integer> newNums2List = nums2List
                        .subList(index + 1, nums2List.size())
                        .stream()
                        .filter(t -> t > num)
                        .toList();
                if (!newNums2List.isEmpty()) {
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


    // Solution
    /**
     * Solution 1
     * 
     * Brute Force (Nested Loop)
     * 
     * Complexities:
     *   n - The Size of `nums1`
     *   m - The Size of `nums2`
     *   - Time Complexity: O(n * m)
     *   - Space Complexity: O(1)
     */
    public int[] solution1(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length];

        for (int i = 0; i < nums1.length; i++) {
            result[i] = -1;
            int j = 0;
            while (j < nums2.length && nums2[j] != nums1[i]) {
                j++;
            }

            for (j++; j < nums2.length; j++) {
                if (nums2[j] > nums1[i]) {
                    result[i] = nums2[j];
                    break;
                }
            }
        }

        return result;
    }

    /**
     * Solution 2
     * 
     * Monotonic Stack + HashMap
     * 
     * Complexities:
     *   n - The Size of `nums1`
     *   m - The Size of `nums2`
     *   - Time Complexity: O(n + m)
     *   - Space Complexity: O(m)
     */
    public int[] solution2(int[] nums1, int[] nums2) {
        Map<Integer, Integer> nextGreater = new HashMap<>();
        Deque<Integer> stack = new ArrayDeque<>();

        for (int n : nums2) {
            while (!stack.isEmpty() && stack.peek() < n) {
                nextGreater.put(stack.pop(), n);
            }
            stack.push(n);
        }

        int[] result = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            result[i] = nextGreater.getOrDefault(nums1[i], -1);
        }

        return result;
    }
}
