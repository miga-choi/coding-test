
class ValidPerfectSquare {
    public boolean isPerfectSquare(int num) {
        int i = 0;
        while (true) {
            if (Math.pow(i, 2) == num) {
                return true;
            } else if (Math.pow(i, 2) > num) {
                return false;
            } else {
                i++;
            }
        }
    }


    // Best Solution
    public boolean bestSolution(int num) {
        long r = num;
        while (r * r > num)
            r = (r + num / r) / 2;
        return r * r == num;
    }
}