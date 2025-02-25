#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is a keyword
int isKeyword(char buffer[]) {
    char keywords[32][10] = {
        "main", "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef",
        "unsigned", "void", "printf", "while"
    };

    for (int i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            return 1;  // It is a keyword
        }
    }
    return 0;  // Not a keyword
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;

    // Open the input file
    fp = fopen("flex_input.txt", "r");
    if (fp == NULL) {
        printf("Error while opening the file\n");
        exit(0);
    }

    // Read characters from the file
    while ((ch = fgetc(fp)) != EOF) {
        // Check if the character is an operator
        for (i = 0; i < 6; ++i) {
            if (ch == operators[i]) {
                printf("%c is an operator\n", ch);
            }
        }

        // Store alphanumeric characters in buffer
        if (isalnum(ch)) {
            buffer[j++] = ch;
        }
        // When a separator (space, newline, punctuation) is found, process buffer
        else if ((ch == ' ' || ch == '\n' || ch == '(' || ch == ')' || ch == ',' || ch == ';' || ch == '{' || ch == '}') && (j != 0)) {
            buffer[j] = '\0';  // Null-terminate the buffer
            j = 0;

            // Check if buffer is a keyword or identifier
            if (isKeyword(buffer)) {
                printf("%s is a keyword\n", buffer);
            } else {
                printf("%s is an identifier\n", buffer);
            }
        }
    }

    fclose(fp);
    return 0;
}
