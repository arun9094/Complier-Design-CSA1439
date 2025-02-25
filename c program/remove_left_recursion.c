#include <stdio.h>
#include <string.h>

#define SIZE 10

int main() {
    char non_terminal;
    char beta, alpha;
    int num;
    char production[SIZE][SIZE];
    int index; // Declare index inside the loop for each production

    printf("Enter Number of Productions: ");
    scanf("%d", &num);

    printf("Enter the grammar in the form A->Aα|β:\n");
    for (int i = 0; i < num; i++) {
        scanf("%s", production[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("\nGRAMMAR: %s", production[i]);
        non_terminal = production[i][0];
        index = 3; // Reset index for each production

        if (non_terminal == production[i][index]) {
            alpha = production[i][index + 1];
            printf(" is left recursive.\n");

            // Find the first occurrence of '|'
            while (production[i][index] != '\0' && production[i][index] != '|')
                index++;

            if (production[i][index] != '\0') {
                beta = production[i][index + 1];
                printf("Grammar without left recursion:\n");
                printf("%c -> %c%c'\n", non_terminal, beta, non_terminal);
                printf("%c' -> %c%c' | ε\n", non_terminal, alpha, non_terminal);
            } else {
                printf("Cannot be reduced (only left-recursive rules present).\n");
            }
        } else {
            printf(" is not left recursive.\n");
        }
    }

    return 0;
}
