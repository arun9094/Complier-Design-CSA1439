#include <stdio.h>

int main() {
    char ch;
    int words = 0, lines = 0, characters = 0;
    int inWord = 0;

    printf("Enter text (Press Ctrl+D to end input on Linux/macOS or Ctrl+Z on Windows):\n");

    while ((ch = getchar()) != EOF) {  // Read input character-by-character
        characters++;

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (inWord) {
                words++;
                inWord = 0;
            }
            if (ch == '\n') {
                lines++;
            }
        } else {
            inWord = 1;
        }
    }

    // If the last word was not followed by space or newline
    if (inWord) {
        words++;
    }

    printf("\nTotal number of words : %d\n", words);
    printf("Total number of lines : %d\n", lines);
    printf("Total number of characters : %d\n", characters);

    return 0;
}
