class NimGame {
    public boolean canWinNim(int n) {
        if (n % 4 == 0) {
            return false;
        }
        return true;
    }


    // Solution
    public boolean solution(int n) {
        return (n % 4 != 0);
    }
}
