#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char  *argv[])
{
    if (argv[1] == NULL || argv[2] != NULL) {
        printf("Usage: vig k\n");
        return 1;
    }

    char *ite;
    for (ite = &argv[1][0]; *ite != '\0'; ite++) {
        if (!isalpha(*ite)) {
            printf("Error: only enter alphabetical character\n");
            return 1;
        }
    }

    char cipher[100];
    strcpy(cipher, argv[1]);

    int cipVal[strlen(cipher)];
    
    //create array with equivalent integers of array
    int index = 0;
    for (; index < strlen(cipher); index++) {
        if (islower(cipher[index])) {
            cipVal[index] = ((int) cipher[index]) - 97; // ASCII a = 97
        }
        else {
            cipVal[index] = ((int) cipher[index]) - 65; // ASCII A = 65
        }
    }

    char input[100];
    printf("plaintext: ");
    scanf("%[^\n]s", &input);
    printf("ciphertext: ");

    // A - Z (65 - 90)
    // a - z (97 - 121)
    
    char *str;
    index = 0;
    int lowerLimit, upperLimit, rot;
    for (str = &input[0]; *str != '\0'; str++) {
        if (!isalpha(*str)) {
            printf("%c", *str);
            continue;
        }
        else if (*str == ' ') {
            printf(" ");
            continue;
        }

        if (islower(*str)) {
            lowerLimit = 97;
            upperLimit = 122;
        }
        else {
            lowerLimit = 65;
            upperLimit = 90;
        }

        rot = ((int) *str) + cipVal[index];
        if (rot > upperLimit) {
            rot = (rot - upperLimit) + lowerLimit - 1;
        }

        printf("%c, cipVal[%d] = %d\n", rot, index, cipVal[index]);

        index++;
        if (index == strlen(cipher)) {
            index = 0;
        }
       
    }

    printf("\n");

    return 0;
}
