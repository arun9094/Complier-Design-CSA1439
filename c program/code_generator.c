#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char a[50][50];

    printf("Enter the number of intermediate code lines: ");
    scanf("%d", &n);
    getchar(); // To consume the newline left in the buffer

    for(i = 0; i < n; i++) {
        printf("Enter the 3-address code %d: ", i + 1);
        fgets(a[i], sizeof(a[i]), stdin); // Read the entire line
        a[i][strcspn(a[i], "\n")] = '\0'; // Remove the trailing newline
    }

    printf("\nGenerated Assembly Code:");
    for(i = 0; i < n; i++) {
        printf("\n mov %c, R%d", a[i][3], i);

        if(a[i][4] == '-') {
            printf("\n sub %c, R%d", a[i][5], i);
        } else if(a[i][4] == '+') {
            printf("\n add %c, R%d", a[i][5], i);
        } else if(a[i][4] == '*') {
            printf("\n mul %c, R%d", a[i][5], i);
        } else if(a[i][4] == '/') {
            printf("\n div %c, R%d", a[i][5], i);
        }

        printf("\n mov R%d, %c", i, a[i][1]);
    }

    printf("\n");
    return 0;
}
