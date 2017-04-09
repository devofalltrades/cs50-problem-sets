#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argv[1] == NULL) {
        printf("Error: invalid argument");
        return 1;
    }

    int key = atoi(argv[1]);
    if (key > 26) {
        key = key % 26;
    }

    // A - Z (65 - 90)
    // a - z (97 - 122)
    
    char input[100];

    printf("plaintext: ");
    scanf("%[^\n]s", &input);
    printf("ciphertext: ");

    char *str;
    int lowerLimit, upperLimit, rot;
    for (str = &input[0]; *str != '\0'; str++) {
        if (!isalpha(*str)) {
            printf("%c", *str);
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

        rot = ((int) *str) + key;
        if (rot > upperLimit) {
            rot = (rot - upperLimit) - 1 + lowerLimit;
        }

        printf("%c", rot);
    }

    printf("\n");
    return 0;
}
