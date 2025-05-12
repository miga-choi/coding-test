class FibonacciNumber {
    public int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fib(n - 1) + fib(n - 2);
        }
    }


    // Solution 1: Iterative
    public int solution1(int n) {
        if (n <= 1) {
            return n;
        }

        int a = 0, b = 1;

        while (n-- > 1) {
            int sum = a + b;
            a = b;
            b = sum;
        }
        return b;
    }

    // Solution 2: Recursive
    public int solution2(int n) {
        if (n <= 1) {
            return n;
        } else {
            return fib(n - 1) + fib(n - 2);
        }
    }

    // Solution 3: Dynamic Programming - Top Down Approach
    int[] fib_cache = new int[31];

    public int solution3(int n) {
        if (n <= 1) {
            return n;
        } else if (fib_cache[n] != 0) {
            return fib_cache[n];
        } else {
            return fib_cache[n] = fib(n - 1) + fib(n - 2);
        }
    }

    // Solution 4: Dynamic Programming - Bottom Up Approach
    public int solution4(int n) {
        if (n <= 1) {
            return n;
        }

        int[] fib_cache = new int[n + 1];
        fib_cache[1] = 1;

        for (int i = 2; i <= n; i++) {
            fib_cache[i] = fib_cache[i - 1] + fib_cache[i - 2];
        }

        return fib_cache[n];
    }
}
