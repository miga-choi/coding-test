class CanPlaceFlowers {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed.length == 1) {
                if (flowerbed[i] == 0) {
                    n--;
                }
            } else {
                if (i == 0) {
                    if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                } else if (i == flowerbed.length - 1) {
                    if (flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                } else {
                    if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
        }

        return n <= 0;
    }


    // Best Solution
    // Best Solution 1:
    public boolean bestSolution1(int[] flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.length && count < n; i++) {
            if (flowerbed[i] == 0) {
                // get next and prev flower bed slot values. If i lies at the ends the next and
                // prev are considered as 0.
                int next = (i == flowerbed.length - 1) ? 0 : flowerbed[i + 1];
                int prev = (i == 0) ? 0 : flowerbed[i - 1];
                if (next == 0 && prev == 0) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }

        return count == n;
    }

    // Best Solution 2:
    public boolean bestSolution2(int[] flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0)
                    && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
                if (n == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    // Best Solution 3:
    public boolean bestSolution3(int[] flowerbed, int n) {
        int count = 1;
        int result = 0;
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 0) {
                count++;
            } else {
                result += (count - 1) / 2;
                count = 0;
            }
        }
        if (count != 0) {
            result += count / 2;
        }
        return result >= n;
    }
}