
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class DestinationCity {
    /**
     * Set
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    public String destCity(List<List<String>> paths) {
        Set<String> cities = new HashSet<>();

        for (List<String> path : paths) {
            cities.add(path.get(0));
        }

        for (List<String> path : paths) {
            String destination = path.get(1);
            if (!cities.contains(destination)) {
                return destination;
            }
        }

        return "";
    }


    // Solution
    public String solution(List<List<String>> paths) {
        Set<String> set = new HashSet<>();

        for (List<String> l : paths) {
            set.add(l.get(1));
        }

        for (List<String> l : paths) {
            set.remove(l.get(0));
        }

        return set.iterator().next();
    }
}
