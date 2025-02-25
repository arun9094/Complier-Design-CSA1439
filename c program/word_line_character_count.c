#include <stdio.h>

int main() {
    char str[100];
    int words = 0, lines = 0, characters = 0;

    printf("Enter text (up to 100 characters, use ~ to end):\n");
    scanf("%[^~]", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            words++;
        } else if (str[i] == '\n') {
            lines++;
        } else {
            characters++;
        }
    }

    // Check for an empty input
    if (characters > 0) {
        words++; // If there are characters, there is at least one word
        lines++; // If there are characters, there is at least one line
    }

    printf("Total number of words: %d\n", words);
    printf("Total number of lines: %d\n", lines);
    printf("Total number of characters: %d\n", characters);

    return 0;
}
