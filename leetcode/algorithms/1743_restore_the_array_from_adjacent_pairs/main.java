import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

class RestoreTheArrayFromAdjacentPairs {
    /**
     * Graph & Hash Map & Vector
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    public int[] restoreArray(int[][] adjacentPairs) {
        Map<Integer, List<Integer>> adjacentMap = new HashMap<>();

        for (int[] adjacentPair : adjacentPairs) {
            int v1 = adjacentPair[0];
            int v2 = adjacentPair[1];

            if (!adjacentMap.containsKey(v1)) {
                adjacentMap.put(v1, new ArrayList<>());
            }
            if (!adjacentMap.containsKey(v2)) {
                adjacentMap.put(v2, new ArrayList<>());
            }

            adjacentMap.get(v1).add(v2);
            adjacentMap.get(v2).add(v1);
        }

        int start = 0;
        for (Map.Entry<Integer, List<Integer>> map : adjacentMap.entrySet()) {
            if (map.getValue().size() == 1) {
                start = map.getKey();
                break;
            }
        }

        int length = adjacentPairs.length + 1;
        int[] result = new int[length];
        int curr = start;
        int prev = -100001;

        for (int i = 0; i < length; i++) {
            result[i] = curr;

            List<Integer> neighbors = adjacentMap.get(curr);

            int next;
            if (neighbors.size() == 1 || neighbors.get(0) != prev) {
                next = neighbors.get(0);
            } else {
                next = neighbors.get(1);
            }

            prev = curr;
            curr = next;
        }

        return result;
    }


    // Solution
    public int[] solution(int[][] adjacentPairs) {
        // length of restoredArray would be input `length + 1`
        int[] restoredArray = new int[adjacentPairs.length + 1];

        Map<Integer, List<Integer>> graph = new HashMap<>();

        // 1. Build graph of number -> [adjacent numbers]
        for (int[] adjacentPair : adjacentPairs) {
            addToGraph(graph, adjacentPair[0], adjacentPair[1]);
            addToGraph(graph, adjacentPair[1], adjacentPair[0]);
        }

        // 2. Find first number with only one adjacent number
        // i.e. `in-degree = 1`. That wil be our start.
        // eg. get `-3` or `-2` as our start.
        // There would always be two elements which satisfy
        // this conditon & starting from either would suffice.
        int start = 0;
        for (int key : graph.keySet()) {
            if (graph.get(key).size() == 1) {
                start = key;
                break;
            }
        }

        // DFS ======>
        Set<Integer> seenSet = new HashSet<>();
        List<Integer> answerList = new ArrayList<>();

        dfs(start, graph, answerList, seenSet);

        for (int i = 0; i < answerList.size(); i++) {
            restoredArray[i] = answerList.get(i);
        }
        // ======> DFS


        // Can use BFS function instead of DFS function
        // BFS ======>
        // bfs(start, graph, restoredArray);
        // ======> BFS

        return restoredArray;
    }

    /****** Template DFS Code *******/
    private void dfs(int start, Map<Integer, List<Integer>> graph, List<Integer> answerList, Set<Integer> seenSet) {
        answerList.add(start);
        seenSet.add(start);
        List<Integer> neighbors = graph.get(start);

        // loop over adjacents like you do in BFS,
        // here adjacents are fetched from the constructed graph.
        for (Integer curr : neighbors) {
            if (!seenSet.contains(curr)) {
                dfs(curr, graph, answerList, seenSet);
            }
        }
    }

    // Utility function which simply builds
    // graph of [numbers] -> [list of adjacent numbers]
    // eg. `[[4, -2],[1, 4],[-3, 1]]`
    // map will be `4 -> [-2, 1]`, `1 -> [-3, 4]`, `-2 -> [4]`, `-3 -> [1]`
    private void addToGraph(Map<Integer, List<Integer>> graph, int key, int value) {
        if (graph.containsKey(key)) {
            graph.get(key).add(value);
        } else {
            List<Integer> temp = new ArrayList<>();
            temp.add(value);
            graph.put(key, temp);
        }
    }

    // One can use this BFS function instead of DFS function as well.
    /****** Template BFS Code *******/
    private void bfs(int start, Map<Integer, List<Integer>> graph, int[] restoredArray) {
        Queue<Integer> bfsQueue = new LinkedList<>();
        Set<Integer> seenSet = new HashSet<Integer>();
        bfsQueue.add(start);
        seenSet.add(start);

        int index = 0;

        while (!bfsQueue.isEmpty()) {

            int restoredValue = bfsQueue.poll();
            List<Integer> neighbors = graph.get(restoredValue);
            restoredArray[index++] = restoredValue;

            // loop over adjacents like you do in BFS
            // here adjacenets are fetched from the constructed graph.
            for (Integer curr : neighbors) {
                if (!seenSet.contains(curr)) {
                    bfsQueue.offer(curr);
                    seenSet.add(curr);
                }
            }
        }
    }
}
