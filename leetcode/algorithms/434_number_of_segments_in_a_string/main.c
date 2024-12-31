#include <string.h>

int countSegments(char* s) {
  int count = 0;
  int begin = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] != ' ') {
      begin = 1;
    }
    if (begin && s[i] == ' ') {
      begin = 0;
      count++;
    }
  }

  return count + begin;
}

// Best Solution
int bestSolution(char* s) {
  if (s == "") {
    return 0;
  }

  int count = 0;
  for (int i = 0; i < strlen(s); i++) {
    if ((s[i] != ' ') && ((s[i + 1] == ' ') || (s[i + 1] == '\0'))) {
      count++;
    }
  }

  return count;
}
