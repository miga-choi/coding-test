#include <stdbool.h>

bool judgeCircle(char* moves) {
    int landscape = 0, portrait = 0;

    for (int i = 0; moves[i] != '\0'; i++) {
        if (moves[i] == 'U') {
            portrait++;
        } else if (moves[i] == 'D') {
            portrait--;
        } else if (moves[i] == 'L') {
            landscape--;
        } else if (moves[i] == 'R') {
            landscape++;
        }
    }

    return !landscape && !portrait;
}

// Solution
bool judgeCircle(char* moves) {
    int v = 0;
    int h = 0;

    for (int i = 0; moves[i] != '\0'; i++) {
        switch (moves[i]) {
            case 'U':
                v++;
                break;
            case 'D':
                v--;
                break;
            case 'R':
                h++;
                break;
            case 'L':
                h--;
                break;
        }
    }

    return v == 0 && h == 0;
}
