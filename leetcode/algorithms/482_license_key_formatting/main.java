class LicenseKeyFormatting {
    public String licenseKeyFormatting(String s, int k) {
        s = s.replaceAll("-", "").toUpperCase();
        String result = "";

        for (int i = s.length(); i >= 0; i -= k) {
            if (i > k) {
                result = "-" + s.substring(i - k, i) + result;
            } else {
                result = s.substring(0, i) + result;
            }
        }

        return result;
    }


    // Solution
    public String solution(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) != '-') {
                sb.append(sb.length() % (k + 1) == k ? '-' : "").append(s.charAt(i));
            }
        }
        return sb.reverse().toString().toUpperCase();
    }
}
