import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

class KeyboardRow {
    public String[] findWords(String[] words) {
        List<String> result = new ArrayList<String>();
        for (String word : words) {
            if (word.toLowerCase().matches("[qwertyuiop]*")
                    || word.toLowerCase().matches("[asdfghjkl]*")
                    || word.toLowerCase().matches("[zxcvbnm]*")) {
                result.add(word);
            }
        }
        return result.toArray(new String[result.size()]);
    }


    // Solution
    public String[] solution(String[] words) {
        return Stream.of(words)
                .filter(s -> s.toLowerCase().matches("[qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*"))
                .toArray(String[]::new);
    }
}
