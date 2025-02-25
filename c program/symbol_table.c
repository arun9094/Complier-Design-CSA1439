#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0; // Counter for symbols in the table

struct symtab {
    char label[20];
    int addr;
} sy[50];

void insert();
int search(char *);
void display();
void modify();

int main() {
    int ch, val;
    char lab[20];

    do {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Modify\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the label to search: ");
                scanf("%s", lab);
                val = search(lab);
                if (val == 1)
                    printf("Label is found.\n");
                else
                    printf("Label is not found.\n");
                break;
            case 4:
                modify();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch < 5);

    return 0;
}

void insert() {
    int val;
    char lab[20];

    printf("Enter the label: ");
    scanf("%s", lab);

    val = search(lab);
    if (val == 1)
        printf("Duplicate symbol. Insertion failed.\n");
    else {
        strcpy(sy[cnt].label, lab);
        printf("Enter the address: ");
        scanf("%d", &sy[cnt].addr);
        cnt++;
        printf("Symbol inserted successfully.\n");
    }
}

int search(char *s) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(sy[i].label, s) == 0)
            return 1; // Symbol found
    }
    return 0; // Symbol not found
}

void modify() {
    int val, ad;
    char lab[20];

    printf("Enter the label to modify: ");
    scanf("%s", lab);

    val = search(lab);
    if (val == 0) {
        printf("No such symbol found.\n");
    } else {
        printf("Label found.\nEnter the new address: ");
        scanf("%d", &ad);

        for (int i = 0; i < cnt; i++) {
            if (strcmp(sy[i].label, lab) == 0) {
                sy[i].addr = ad;
                printf("Address updated successfully.\n");
                return;
            }
        }
    }
}

void display() {
    if (cnt == 0) {
        printf("Symbol table is empty.\n");
        return;
    }

    printf("\nSymbol Table:\n");
    printf("Label\tAddress\n");
    printf("----------------\n");

    for (int i = 0; i < cnt; i++)
        printf("%s\t%d\n", sy[i].label, sy[i].addr);
}
