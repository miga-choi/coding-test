public class PlusOne {
    public int[] PlusOne(int[] digits) {
        int sum = 0;
        List<int> result = new List<int>();
        int up = 1;

        for (int i = digits.Length - 1; i >= 0; i--) {
            int num = digits[i] + up;

            if (num >= 10) {
                num -= 10;
                up = 1;
            } else {
                up = 0;
            }

            result.Insert(0, num);
        }

        if (up > 0) {
            result.Insert(0, 1);
        }

        return result.ToArray();
    }


    // Solution
    // Solution 1:
    public int[] solution1(int[] digits) {
        int n = digits.Length;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        int[] newNumber = new int[n + 1];
        newNumber[0] = 1;

        return newNumber;
    }

    // Solution 2:
    public int[] solution2(int[] digits) {
        for (int i = digits.Length - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        int[] firstOne = new int[] { 1 };
        return firstOne.Concat(digits).ToArray();
    }

    // Solution 3:
    public int[] solution3(int[] digits) {
        int len = digits.Length;
        int num;
        int add = 1;

        for (int i = len - 1; i >= 0; i--) {
            num = digits[i] + add;
            if (num == 10) {
                digits[i] = 0;
            } else {
                digits[i] = num;
                return digits;
            }
        }

        int[] newDigits = new int[digits.Length + 1];

        newDigits[0] = 1;
        Array.Copy(digits, 0, newDigits, 1, digits.Length);

        return newDigits;
    }
}
