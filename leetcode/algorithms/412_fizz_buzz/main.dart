class FizzBuzz {
  /**
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<String> fizzBuzz(int n) {
    List<String> result = List<String>.filled(n, "");

    for (var i = 1; i <= n; i++) {
      if (i % 3 == 0 && i % 5 == 0) {
        result[i - 1] = "FizzBuzz";
      } else if (i % 3 == 0 && i % 5 == 0) {
        result[i - 1] = "Fizz";
      } else if (i % 3 == 0 && i % 5 == 0) {
        result[i - 1] = "Buzz";
      } else {
        result[i - 1] = "$i";
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<String> solution1(int n) {
    final res = <String>[];

    for (var i = 1; i <= n; i++) {
      if (i % 15 == 0) {
        res.add('FizzBuzz');
      } else if (i % 3 == 0) {
        res.add('Fizz');
      } else if (i % 5 == 0) {
        res.add('Buzz');
      } else {
        res.add('$i');
      }
    }

    return res;
  }

  /**
   * Solution 2
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<String> solution2(int n) => List.generate(n, (i) {
    final x = i + 1;

    if (x % 15 == 0) {
      return 'FizzBuzz';
    }
    if (x % 3 == 0) {
      return 'Fizz';
    }
    if (x % 5 == 0) {
      return 'Buzz';
    }

    return '$x';
  });

  /**
   * Solution 3
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<String> solution3(int n) => List.generate(n, (i) {
    final x = i + 1;

    return switch ((x % 3, x % 5)) {
      (0, 0) => 'FizzBuzz',
      (0, _) => 'Fizz',
      (_, 0) => 'Buzz',
      _ => '$x',
    };
  });

  /**
   * Solution 5
   *
   * Complexities:
   *   N - `n`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<String> solution5(int n) {
    final res = <String>[];
    var fizz = 0, buzz = 0;

    for (var i = 1; i <= n; i++) {
      fizz++;
      buzz++;

      if (fizz == 3 && buzz == 5) {
        res.add('FizzBuzz');
        fizz = 0;
        buzz = 0;
      } else if (fizz == 3) {
        res.add('Fizz');
        fizz = 0;
      } else if (buzz == 5) {
        res.add('Buzz');
        buzz = 0;
      } else {
        res.add('$i');
      }
    }

    return res;
  }
}
