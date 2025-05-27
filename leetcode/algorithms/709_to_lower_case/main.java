
import java.util.stream.IntStream;

class ToLowerCase {
    public String toLowerCase(String s) {
        char[] charArray = s.toCharArray();

        for (int i = 0; i < charArray.length; i++) {
            if (charArray[i] >= 'A' && charArray[i] <= 'Z') {
                charArray[i] += 32;
            }
        }

        return new String(charArray);
    }


    // Solution
    // Solution 1
    public String solution1(String str) {
        char[] a = str.toCharArray();

        for (int i = 0; i < a.length; i++) {
            if ('A' <= a[i] && a[i] <= 'Z') {
                a[i] = (char) (a[i] - 'A' + 'a');
            }
        }

        return new String(a);
    }

    // Solution 2: Using streams
    public String solution2(String s) {
        char[] a = s.toCharArray();

        IntStream.range(0, a.length)
                .filter(i -> 'A' <= a[i] && a[i] <= 'Z')
                .forEach(i -> a[i] = (char) (a[i] - 'A' + 'a'));

        return new String(a);
    }
}
