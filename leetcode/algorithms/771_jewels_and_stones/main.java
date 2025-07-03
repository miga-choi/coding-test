import java.util.HashSet;
import java.util.Set;

class JewelsAndStones {
    public int numJewelsInStones(String jewels, String stones) {
        int[] numsArray = new int[128];
        for (char jewel : jewels.toCharArray()) {
            numsArray[jewel] = 1;
        }

        int count = 0;
        for (char stone : stones.toCharArray()) {
            count += numsArray[stone];
        }

        return count;
    }


    // Solution
    // Solution 1
    public int solution1(String jewels, String stones) {
        return stones.replaceAll("[^" + jewels + "]", "").length();
    }

    // Solution 2: HashSet
    public int solution2(String jewels, String stones) {
        Set<Character> jewelsSet = new HashSet<Character>();
        for (char jewel : jewels.toCharArray()) {
            jewelsSet.add(jewel);
        }

        int res = 0;
        for (char stone : stones.toCharArray()) {
            if (jewelsSet.contains(stone)) {
                res++;
            }
        }

        return res;
    }
}
