#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char a[50]; // Increased buffer size for longer identifiers
    int flag = 1, i = 1;

    printf("\nEnter an identifier: ");
    fgets(a, sizeof(a), stdin);

    // Remove trailing newline if present
    size_t len = strlen(a);
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
    }

    // Check if the first character is a letter or underscore
    if (isalpha(a[0]) || a[0] == '_') {
        while (a[i] != '\0') {
            if (!isalnum(a[i]) && a[i] != '_') { // Allow alphanumeric characters and underscores
                flag = 0;
                break;
            }
            i++;
        }
    } else {
        flag = 0;
    }

    if (flag == 1) {
        printf("\nValid identifier\n");
    } else {
        printf("\nNot a valid identifier\n"); // Fixed the issue of extra character
    }

    return 0;
}

