#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char A[100000];
    char S[4];

    scanf("%s", A);
    scanf("%s", S);


    int lenA = strlen(A);
    int lenS = strlen(S);
    int count = 0;
    int j = 0;

    if (S[2] == 'X') {
        for (int i = 0; i < 2; i++) {
            while (j < lenA && tolower(S[i]) != tolower(A[j])) {
                j++;
            }
            if (j < lenA) {
                count++;
                j++;
            } else {
                break;
            }
        }
    } else {
        for (int i = 0; i < lenS; i++) {
            while (j < lenA && tolower(S[i]) != tolower(A[j])) {
                j++;
            }
            if (j < lenA) {
                count++;
                j++;
            } else {
                break;
            }
        }
    }

    if ((S[2] == 'X' && count == 2) || (S[2] != 'X' && count == 3)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}