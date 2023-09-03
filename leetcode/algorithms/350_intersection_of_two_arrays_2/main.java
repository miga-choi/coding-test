import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class IntersectionOfTwoArrays2 {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> result = new ArrayList<Integer>();
        Map<Integer, Integer> numsMap = new HashMap<Integer, Integer>();

        for (Integer num1 : nums1) {
            if (numsMap.get(num1) == null) {
                numsMap.put(num1, 1);
            } else {
                numsMap.put(num1, numsMap.get(num1) + 1);
            }
        }

        for (Integer num2 : nums2) {
            if (numsMap.get(num2) != null && numsMap.get(num2) > 0) {
                result.add(num2);
                numsMap.put(num2, numsMap.get(num2) - 1);
            }
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }


    // Best Solution
    public int[] bestSolution1(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : nums1) {
            int freq = map.getOrDefault(i, 0);
            map.put(i, freq + 1);
        }
        ArrayList<Integer> list = new ArrayList<>();
        for (int i : nums2) {
            if (map.get(i) != null && map.get(i) > 0) {
                list.add(i);
                map.put(i, map.get(i) - 1);
            }
        }
        int[] ret = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }

    public int[] bestSolution2(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int n = nums1.length, m = nums2.length;
        int i = 0, j = 0;
        List<Integer> list = new ArrayList<>();
        while (i < n && j < m) {
            int a = nums1[i], b = nums2[j];
            if (a == b) {
                list.add(a);
                i++;
                j++;
            } else if (a < b) {
                i++;
            } else {
                j++;
            }
        }
        int[] ret = new int[list.size()];
        for (int k = 0; k < list.size(); k++)
            ret[k] = list.get(k);
        return ret;
    }
}