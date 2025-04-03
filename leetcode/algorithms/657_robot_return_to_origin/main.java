class RobotReturnToOrigin {
    public boolean judgeCircle(String moves) {
        int landscape = 0, portrait = 0;

        for (String c : moves.split("")) {
            switch (c) {
                case "U":
                    portrait++;
                    break;
                case "D":
                    portrait--;
                    break;
                case "R":
                    landscape++;
                    break;
                case "L":
                    landscape--;
                    break;
            }
        }

        return landscape == 0 && portrait == 0;
    }

    // Solution
    public boolean solution(String moves) {
        int x = 0;
        int y = 0;
        for (char ch : moves.toCharArray()) {
            if (ch == 'U') {
                y++;
            } else if (ch == 'D') {
                y--;
            } else if (ch == 'R') {
                x++;
            } else if (ch == 'L') {
                x--;
            }
        }
        return x == 0 && y == 0;
    }
}
