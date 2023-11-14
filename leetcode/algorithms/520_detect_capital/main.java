class DetectCapital {
    public boolean detectCapitalUse(String word) {
        return word.equals(word.toUpperCase())
                || word.equals(word.toLowerCase())
                || word.equals(word.substring(0, 1).toUpperCase() + word.substring(1).toLowerCase());
    }


    // Best Solution
    public boolean bestSolution1(String word) {
        int cnt = 0;
        for (char c : word.toCharArray()) {
            if ('Z' - c >= 0) {
                cnt++;
            }
        }
        return ((cnt == 0 || cnt == word.length()) || (cnt == 1 && 'Z' - word.charAt(0) >= 0));
    }

    public boolean bestSolution2(String word) {
        return word.matches("[A-Z]+|[a-z]+|[A-Z][a-z]+");
    }

    public boolean bestSolution3(String word) {
        if (word.length() == 0 || word.length() == 1) {
            return true;
        }
        if (Character.isUpperCase(word.charAt(0))) {
            boolean isFirstCharacter = Character.isUpperCase(word.charAt(1));
            for (int i = 2; i < word.length(); i++) {
                boolean currentCharState = Character.isUpperCase(word.charAt(i));
                if (currentCharState != isFirstCharacter) {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < word.length(); i++) {
                if (Character.isUpperCase(word.charAt(i))) {
                    return false;
                }
            }
        }
        return true;
    }
}