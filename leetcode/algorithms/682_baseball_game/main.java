import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class BaseballGame {
    public int calPoints(String[] operations) {
        List<Integer> scoreArray = new ArrayList<Integer>();

        for (String operation : operations) {
            if (operation.equals("+")) {
                scoreArray.add(scoreArray.get(scoreArray.size() - 2) + scoreArray.get(scoreArray.size() - 1));
            } else if (operation.equals("D")) {
                scoreArray.add(scoreArray.get(scoreArray.size() - 1) * 2);
            } else if (operation.equals("C")) {
                scoreArray.removeLast();
            } else {
                scoreArray.add(Integer.parseInt(operation));
            }
        }

        return scoreArray.stream().mapToInt(i -> i).sum();
    }


    // Solution
    public int solution(String[] ops) {
        Stack<Integer> stack = new Stack<Integer>();

        for (String op : ops) {
            if (op.equals("+")) {
                int top = stack.pop();
                int newtop = top + stack.peek();
                stack.push(top);
                stack.push(newtop);
            } else if (op.equals("C")) {
                stack.pop();
            } else if (op.equals("D")) {
                stack.push(2 * stack.peek());
            } else {
                stack.push(Integer.valueOf(op));
            }
        }

        int ans = 0;
        for (int score : stack) {
            ans += score;
        }

        return ans;
    }
}
