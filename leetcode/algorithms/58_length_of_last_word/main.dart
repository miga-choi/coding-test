class LengthOfLastWord {
  int lengthOfLastWord(String s) {
    List<String> sArray = s.trim().split(" ");
    for (var i = sArray.length - 1; i >= 0; i--) {
      if (sArray[i].trim().length > 0) {
        return sArray[i].length;
      }
    }
    return 0;
  }

  // Best Solution
  int bestSolution(String s) {
    // Initialize the index variable to the last index of the string
    int index = s.length - 1;
    // Loop through any trailing spaces at the end of the string
    while (s[index] == " ") {
      index--;
    }
    // Initialize the count variable to 0
    int count = 0;
    // Loop through the last word in the string
    while (s[index] != " ") {
      // Increment the count variable for each character in the last word
      count++;
      // Check if the previous character was a space or if we have reached the beginning of the string
      if (s[index] == " " || index == 0) {
        // Break out of the loop if the previous character was a space or if we have reached the beginning of the string
        break;
      }
      // Move the index to the previous character in the string
      index--;
    }
    // Return the count variable which contains the length of the last word in the string
    return count;
  }
}
