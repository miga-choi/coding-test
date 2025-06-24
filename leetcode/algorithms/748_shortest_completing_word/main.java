class ShortestCompletingWord {
    boolean isCompleting(int[] plateFreq, String word) {
        int[] wordFreq = new int[26];

        for (int i = 0; i < word.length(); i++) {
            int index = word.charAt(i) - 'a';
            wordFreq[index]++;
        }

        for (int i = 0; i < 26; i++) {
            if (wordFreq[i] < plateFreq[i]) {
                return false;
            }
        }

        return true;
    }

    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] plateFreq = new int[26];

        licensePlate = licensePlate.toLowerCase();

        for (int i = 0; i < licensePlate.length(); i++) {
            int charCode = licensePlate.charAt(i) - 'a';
            if (charCode >= 0 && charCode < 26) {
                plateFreq[charCode]++;
            }
        }

        String shortestWord = "";
        int minLength = 15;

        for (String word : words) {
            int currentLength = word.length();

            if (currentLength >= minLength) {
                continue;
            }

            if (isCompleting(plateFreq, word)) {
                minLength = currentLength;
                shortestWord = word;
            }
        }

        return shortestWord;
    }


    // Solution
    private static final int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
            73, 79, 83, 89, 97, 101 };

    private long getCharProduct(String plate) {
        long product = 1L;

        for (char c : plate.toCharArray()) {
            int index = c - 'a';
            if (0 <= index && index <= 25) {
                product *= primes[index];
            }
        }

        return product;
    }

    public String solution(String licensePlate, String[] words) {
        long charProduct = getCharProduct(licensePlate.toLowerCase());
        String shortest = "aaaaaaaaaaaaaaaaaaaa"; // 16 a's

        for (String word : words) {
            if (word.length() < shortest.length() && getCharProduct(word) % charProduct == 0) {
                shortest = word;
            }
        }

        return shortest;
    }
}
