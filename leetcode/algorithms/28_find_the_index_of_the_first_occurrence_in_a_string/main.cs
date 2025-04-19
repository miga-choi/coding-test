public class FindTheIndexOfTheFirstOccurrenceInAString {
    public int StrStr(string haystack, string needle) {
        return haystack.IndexOf(needle);
    }


    // Solution
    // Solution 1:
    public int solution1(string haystack, string needle) {
        for (var i = 0; i < haystack.Length - needle.Length + 1; i++) {
            if (haystack.Substring(i, needle.Length) == needle) {
                return i;
            }
        }

        return -1;
    }

    // Solution 2:
    public int solution2(string haystack, string needle) {
        return haystack.IndexOf(needle);
    }

    // Solution 3:
    public int solution3(string haystack, string needle) {
        int result = -1;
        int matchLoc = 0;

        for (int i = 0; i < haystack.Length; i++) {
            if (haystack[i] == needle[matchLoc]) {
                matchLoc++;
                if (matchLoc == needle.Length) {
                    result = i - matchLoc + 1;
                    break;
                }
            } else {
                i -= matchLoc;
                matchLoc = 0;
            }
        }
        return result;
    }
}
