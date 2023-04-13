import java.text.SimpleDateFormat;
import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        List<Integer> answer = new ArrayList<Integer>();
        try {
            Map<String, Integer> termsMap = new HashMap<>();
            for (String term : terms) {
                String[] termArray = term.split(" ");
                termsMap.put(termArray[0], Integer.parseInt(termArray[1]));
            }

            SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy.MM.dd");
            for (int i = 0; i < privacies.length; i++) {
                String[] privacyArray = privacies[i].split(" ");
                Date todayDate = simpleDateFormat.parse(today);
                Date date = simpleDateFormat.parse(privacyArray[0]);
                Calendar cal = Calendar.getInstance();
                cal.setTime(date);
                cal.add(Calendar.MONTH, termsMap.get(privacyArray[1]));
                Date newDate = cal.getTime();
                if (todayDate.compareTo(newDate) >= 0) {
                    answer.add(i + 1);
                }
            }
        } catch (Exception error_) {
            System.out.println(error_);
        }
        return answer.stream().mapToInt(integer -> integer).toArray();
    }
}