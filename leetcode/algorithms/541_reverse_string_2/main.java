class ReverseStringII {
    public String reverseStr(String s, int k) {
        if (s.length() < k) {
            return new StringBuffer(s).reverse().toString();
        }

        String result = "";
        for (int i = 0; i < s.length(); i += 2 * k) {
            String stringK = "";
            String string2K = "";
            if (i + k <= s.length()) {
                stringK = s.substring(i, i + k);
                if (i + 2 * k <= s.length()) {
                    string2K = s.substring(i + k, i + 2 * k);
                } else {
                    string2K = s.substring(i + k);
                }
            } else {
                stringK = s.substring(i);
            }
            result += new StringBuffer(stringK).reverse().toString() + string2K;
        }

        return result;
    }


    // Best Solution
    public String bestSolution1(String s, int k) {
        char[] arr = s.toCharArray();
        int n = arr.length;
        int i = 0;
        while (i < n) {
            int j = Math.min(i + k - 1, n - 1);
            swap(arr, i, j);
            i += 2 * k;
        }
        return String.valueOf(arr);
    }

    private void swap(char[] arr, int l, int r) {
        while (l < r) {
            char temp = arr[l];
            arr[l++] = arr[r];
            arr[r--] = temp;
        }
    }


    public String bestSolution2(String s, int k) {
        char[] ca = s.toCharArray();
        for (int left = 0; left < ca.length; left += 2 * k) {
            for (int i = left, j = Math.min(left + k - 1, ca.length - 1); i < j; i++, j--) {
                char tmp = ca[i];
                ca[i] = ca[j];
                ca[j] = tmp;
            }
        }
        return new String(ca);
    }
}
