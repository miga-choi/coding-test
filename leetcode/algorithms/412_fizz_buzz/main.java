import java.util.ArrayList;
import java.util.List;

class FizzBuzz {
    /**
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public List<String> fizzBuzz(int n) {
        List<String> result = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                result.add("FizzBuzz");
            } else if (i % 3 == 0) {
                result.add("Fizz");
            } else if (i % 5 == 0) {
                result.add("Buzz");
            } else {
                result.add(String.format("%d", i));
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public List<String> solution1(int n) {
        List<String> result = new ArrayList<>(n);

        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                result.add("FizzBuzz");
            } else if (i % 3 == 0) {
                result.add("Fizz");
            } else if (i % 5 == 0) {
                result.add("Buzz");
            } else {
                result.add(String.valueOf(i));
            }
        }

        return result;
    }

    /**
     * Solution 2
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public List<String> solution2(int n) {
        List<String> result = new ArrayList<>(n);

        for (int i = 1; i <= n; i++) {
            StringBuilder sb = new StringBuilder();

            if (i % 3 == 0) {
                sb.append("Fizz");
            }
            if (i % 5 == 0) {
                sb.append("Buzz");
            }

            result.add(sb.length() > 0 ? sb.toString() : String.valueOf(i));
        }

        return result;
    }

    /**
     * Solution 3
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public List<String> solution3(int n) {
        List<String> result = new ArrayList<>(n);
        int fizz = 0, buzz = 0;

        for (int i = 1; i <= n; i++) {
            fizz++;
            buzz++;

            if (fizz == 3 && buzz == 5) {
                result.add("FizzBuzz");
                fizz = 0;
                buzz = 0;
            } else if (fizz == 3) {
                result.add("Fizz");
                fizz = 0;
            } else if (buzz == 5) {
                result.add("Buzz");
                buzz = 0;
            } else {
                result.add(String.valueOf(i));
            }
        }

        return result;
    }
}
