class OneBitAndTwoBitCharacters {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;

        while (i < bits.length - 1) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                i += 1;
            }
        }

        return i == bits.length - 1;
    }


    // Solution
    // Solution 1: Increment Pointer
    public boolean solution1(int[] bits) {
        int i = 0;

        while (i < bits.length - 1) {
            i += bits[i] + 1;
        }

        return i == bits.length - 1;
    }

    // Solution 2: Greedy
    public boolean solution2(int[] bits) {
        int i = bits.length - 2;

        while (i >= 0 && bits[i] > 0) {
            i--;
        }

        return (bits.length - i) % 2 == 0;
    }
}
