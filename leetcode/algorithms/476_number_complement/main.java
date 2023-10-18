class NumberComplement {
    public int findComplement(int num) {
        String[] binary = Integer.toBinaryString(num).split("");
        String result = "";

        for (String b : binary) {
            if (b.equals("1")) {
                result += "0";
            } else {
                result += "1";
            }
        }

        return Integer.parseInt(result, 2);
    }


    // Best Solution
    public int bestSolution(int num) {
        int i = 0;
        int j = 0;

        while (i < num) {
            i += Math.pow(2, j);
            j++;
        }

        return i - num;
    }
}