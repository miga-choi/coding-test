import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

class IntersectionOfTwoArrays {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> result = new HashSet<Integer>();

        for (int num1 : nums1) {
            for (int num2 : nums2) {
                if (num1 == num2) {
                    result.add(num1);
                }
            }
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }


    // Solution
    public int[] solution(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<Integer>();
        ArrayList<Integer> res = new ArrayList<Integer>();

        // Add all elements to set from array 1
        for (int i = 0; i < nums1.length; i++) {
            set.add(nums1[i]);
        }

        for (int j = 0; j < nums2.length; j++) {
            // If present in array 2 then add to res and remove from set
            if (set.contains(nums2[j])) {
                res.add(nums2[j]);
                set.remove(nums2[j]);
            }
        }

        // Convert ArrayList to array
        int[] arr = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            arr[i] = res.get(i);
        }

        return arr;
    }
}
