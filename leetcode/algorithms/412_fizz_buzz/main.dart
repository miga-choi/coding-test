class FizzBuzz {
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
  List<String> solution(int n) {
    var v = new List.filled(n, "");

    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 && i % 5 == 0) {
        v[i - 1] = ("FizzBuzz");
      } else if (i % 3 == 0) {
        v[i - 1] = ("Fizz");
      } else if (i % 5 == 0) {
        v[i - 1] = ("Buzz");
      } else {
        v[i - 1] = (i.toString());
      }
    }

    return v;
  }
}
