import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class ConvertANumberToHexadecimal {
    public String toHex(int num) {
        long longNum = num;
        List<String> hex = new ArrayList<String>(
                Arrays.asList("0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"));

        if (longNum == 0) {
            return hex.get(0);
        }

        if (longNum < 0) {
            longNum += Math.pow(2, 32);
        }

        String result = "";

        while (longNum > 0) {
            long remainder = longNum % 16;
            result = hex.get((int) remainder) + result;
            longNum = Math.floorDiv(longNum, 16);
        }

        return result;
    }


    // Solution
    public String solution(int num) {
        char[] map = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

        if (num == 0) {
            return "0";
        }

        String result = "";
        while (num != 0) {
            result = map[(num & 15)] + result;
            num = (num >>> 4);
        }

        return result;
    }
}