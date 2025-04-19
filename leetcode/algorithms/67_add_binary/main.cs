using System;

public class AddBinary {
    public string AddBinary(string a, string b) {
        int length = a.Length > b.Length ? a.Length : b.Length;
        int up = 0;
        string result = "";
        for (int i = 0; i < length; i++) {
            int num = up;
            up = 0;
            if (a.Length > i) {
                num += a[a.Length - i - 1] - '0';
            }
            if (b.Length > i) {
                num += b[b.Length - i - 1] - '0';
            }

            if (num > 1) {
                num -= 2;
                up = 1;
            }

            result = num.ToString() + result;
        }

        if (up > 0) {
            result = "1" + result;
        }

        return result;
    }


    // Solution
    // Solution 1:
    public string solution1(string a, string b) {
        var sb = new StringBuilder();
        var t = 0;
        for (int i = a.Length - 1, j = b.Length - 1; i >= 0 || j >= 0 || t > 0; i--, j--) {
            var av = i < 0 || a[i] == '0' ? 0 : 1;
            var bv = j < 0 || b[j] == '0' ? 0 : 1;
            sb.Insert(0, (av + bv + t) % 2);
            t = (av + bv + t) / 2;
        }

        return sb.ToString();
    }

    // Solution 2:
    public string solution2(string a, string b) {
        if (x == 1) {
            return x;
        }
        for (double i = 0; i <= x; i++) {
            if (i * i > x) {
                return Convert.ToInt32(i - 1);
            }
        }
        return 0;
    }
}
