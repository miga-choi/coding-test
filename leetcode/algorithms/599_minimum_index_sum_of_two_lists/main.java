import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class MinimumIndexSumOfTwoLists {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> map1 = new HashMap<String, Integer>();
        Map<String, Integer> map2 = new HashMap<String, Integer>();

        for (int i = 0; i < list1.length; i++) {
            map1.put(list1[i], i);
        }

        for (int i = 0; i < list2.length; i++) {
            if (map1.get(list2[i]) != null) {
                map2.put(list2[i], map1.get(list2[i]) + i);
            }
        }

        int minIndex = Collections.min(map2.values());
        List<String> result = new ArrayList<String>();
        for (Map.Entry<String, Integer> v : map2.entrySet()) {
            if (v.getValue() == minIndex) {
                result.add(v.getKey());
            }
        }

        return result.toArray(new String[result.size()]);
    }


    // Best Solution
    // Best Solution 1:
    public String[] bestSolution1(String[] list1, String[] list2) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        List<String> res = new LinkedList<String>();
        int minSum = Integer.MAX_VALUE;
        for (int i = 0; i < list1.length; i++) {
            map.put(list1[i], i);
        }
        for (int i = 0; i < list2.length; i++) {
            Integer j = map.get(list2[i]);
            if (j != null && i + j <= minSum) {
                if (i + j < minSum) {
                    res.clear();
                    minSum = i + j;
                }
                res.add(list2[i]);
            }
        }
        return res.toArray(new String[res.size()]);
    }

    // Best Solution 2: HashMap
    public String[] bestSolution2(String[] list1, String[] list2) {
        if (list1.length > list2.length) {
            return findRestaurant(list2, list1);
        }

        Map<String, Integer> map1 = new HashMap<String, Integer>();
        for (int i = 0; i < list1.length; i++) {
            map1.put(list1[i], i);
        }

        List<String> mins = new ArrayList<>();
        int minSum = Integer.MAX_VALUE;
        for (int i = 0; i < list2.length; i++) {
            String rest2 = list2[i];
            if (map1.containsKey(rest2)) {
                int sum = map1.get(rest2) + i;
                if (sum < minSum) {
                    mins = new ArrayList<String>();
                    minSum = sum;
                }
                if (sum == minSum) {
                    mins.add(rest2);
                }
            }
        }

        return mins.toArray(new String[mins.size()]);
    }
}