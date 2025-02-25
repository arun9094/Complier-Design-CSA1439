#include <stdio.h>
#include <string.h>

int main() {
    char gram[20], part1[20], part2[20], modifiedGram[20], newGram[20];
    int i, j = 0, k = 0, l = 0, pos = -1;

    // Input production
    printf("Enter Production (S->A|B format): S->");
    fgets(gram, sizeof(gram), stdin);
    gram[strcspn(gram, "\n")] = '\0'; // Remove newline character

    // Extract part1 and part2
    for (i = 0; gram[i] != '|' && gram[i] != '\0'; i++, j++)
        part1[j] = gram[i];
    part1[j] = '\0';

    if (gram[i] == '|') {
        j = ++i;
        for (i = 0; gram[j] != '\0'; j++, i++)
            part2[i] = gram[j];
        part2[i] = '\0';
    } else {
        printf("Invalid production format!\n");
        return 1;
    }

    // Find common prefix
    for (i = 0; part1[i] == part2[i] && part1[i] != '\0'; i++) {
        modifiedGram[k++] = part1[i];
        pos = i + 1;
    }

    if (pos == -1) {
        printf("No common prefix found. No left factoring needed.\n");
        return 0;
    }

    // Create modified production
    modifiedGram[k] = 'X';
    modifiedGram[++k] = '\0';

    // Create new production
    for (i = pos, j = 0; part1[i] != '\0'; i++, j++)
        newGram[j] = part1[i];
    if (j > 0) newGram[j++] = '|';

    for (i = pos; part2[i] != '\0'; i++, j++)
        newGram[j] = part2[i];
    newGram[j] = '\0';

    // Print the result
    printf("\nLeft Factored Grammar:\n");
    printf("S -> %s\n", modifiedGram);
    printf("X -> %s\n", newGram);

    return 0;
}
