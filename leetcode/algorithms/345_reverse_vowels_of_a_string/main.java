import java.util.Stack;

class ReverseVowelsOfAString {
    public String reverseVowels(String s) {
        String result = "";
        String[] sArray = s.split("");
        String vowels = "AEIOUaeiou";
        Stack<String> vowelStack = new Stack<String>();

        for (String c : sArray) {
            if (vowels.contains(c)) {
                vowelStack.add(c);
            }
        }

        for (int i = 0; i < sArray.length; i++) {
            if (vowels.contains(sArray[i])) {
                result += vowelStack.pop();
            } else {
                result += sArray[i];
            }
        }

        return result;
    }


    // Best Solution
    public String bestSolution(String s) {
        if (s == null || s.length() == 0)
            return s;
        String vowels = "aeiouAEIOU";
        char[] chars = s.toCharArray();
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {

            while (start < end && !vowels.contains(chars[start] + "")) {
                start++;
            }

            while (start < end && !vowels.contains(chars[end] + "")) {
                end--;
            }

            char temp = chars[start];
            chars[start] = chars[end];
            chars[end] = temp;

            start++;
            end--;
        }
        return new String(chars);
    }
}