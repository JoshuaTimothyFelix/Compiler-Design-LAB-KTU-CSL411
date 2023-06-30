#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10

typedef struct {
    char lhs;
    char rhs[MAX_SYMBOLS];
} Production;

void addToResultSet(char result[], char val) {
        int i;
    for (i = 0; result[i] != '\0'; i++)
        if (result[i] == val)
            return;
    result[i] = val;
    result[i + 1] = '\0';
}

void FIRST(char result[], Production productions[], int numProductions, char symbol) {
    int i, j;
    for (i = 0; i < numProductions; i++)
        if (productions[i].lhs == symbol) {
            if (!isupper(productions[i].rhs[0]))
                addToResultSet(result, productions[i].rhs[0]);
            else
                for (j = 0; productions[i].rhs[j] != '\0'; j++)
                    if (productions[i].rhs[j] != symbol) {
                        FIRST(result, productions, numProductions, productions[i].rhs[j]);
                        break;
                    }
        }
}

int main() {
    int numProductions, i;
    printf("How many number of productions? ");
    scanf("%d", &numProductions);
    Production productions[MAX_PRODUCTIONS];
    for (i = 0; i < numProductions; i++) {
        printf("Enter production Number %d: ", i + 1);
        scanf(" %c=%s", &productions[i].lhs, productions[i].rhs);
    }
    char choice, symbol;
    char result[MAX_SYMBOLS];
    do {
        for (int i = 0; i < MAX_SYMBOLS; i++)
        	result[i] = '\0';  // Set each element to zero
        printf("\nFind the FIRST of: ");
        scanf(" %c", &symbol);
        FIRST(result, productions, numProductions, symbol);
        printf("\nFIRST(%c) = { ", symbol);
        for (i = 0; result[i] != '\0'; i++)
            printf("%c ", result[i]);
        printf("}\n");
        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
