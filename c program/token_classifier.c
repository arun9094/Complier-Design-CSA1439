#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main() {
    int i, ic = 0, cc = 0, oc = 0, m, j;
    char b[100], operators[30], identifiers[30];
    int constants[30]; // Store constants as integers

    printf("Enter the string: ");
    scanf("%[^\n]", b); // Removed unnecessary '&'

    for (i = 0; i < strlen(b); i++) {
        if (isspace(b[i])) {
            continue;
        } else if (isalpha(b[i])) {
            identifiers[ic++] = b[i];
        } else if (isdigit(b[i])) {
            m = (b[i] - '0');
            i++;
            while (isdigit(b[i])) {
                m = m * 10 + (b[i] - '0');
                i++;
            }
            i--; // Adjust for loop increment
            constants[cc++] = m;
        } else {
            if (b[i] == '+' || b[i] == '-' || b[i] == '*' || b[i] == '=') {
                operators[oc++] = b[i];
            }
        }
    }

    // Null-terminate character arrays
    identifiers[ic] = '\0';
    operators[oc] = '\0';

    // Output the classified tokens
    printf("\nIdentifiers: ");
    for (j = 0; j < ic; j++) {
        printf("%c ", identifiers[j]);
    }

    printf("\nConstants: ");
    for (j = 0; j < cc; j++) {
        printf("%d ", constants[j]);
    }

    printf("\nOperators: ");
    for (j = 0; j < oc; j++) {
        printf("%c ", operators[j]);
    }

    return 0;
}
