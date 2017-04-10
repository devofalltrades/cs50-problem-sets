/*
    Cracked Hashes
        andi:50.jPgLzVirkc => hi
        jason:50YHuxoCN9Jkc => JH
        malan:50QvlJWn2qJGE => NOPE
        mzlatkova:50CPlMDLT06yY => ha
        patrick:50WUNAFdX/yjA => Yale
        rbowden:50fkUxYHbnXGw => rofl
        summer:50C6B0oz0HWzo => FTW
        stelios:50nq4RV/NVU0I => ABC
        wmartin:50vtwu4ujL.Dk => haha
        zamyla:50i2t3sOSAZtk => lol
*/

#include <stdio.h>
#include <string.h>

#include <unistd.h>
#define _XOPEN_SOURCE

char* crypt (const char *key, const char *salt);

int main(int argc, char *argv[])
{
    if (argv[1] == NULL || argv[2] != NULL) {
        printf("Usage: ./crack (hash)\n");
        return 1;
    }
    
    char salt[3];
    strncpy(salt, argv[1], 2);
    salt[2] = '\0';
    
    int buffSize = 52;
    char buffer[52];
    int buffIndex = 0;
    for (buffIndex = 0; buffIndex < 26; buffIndex++) { //small alphabet into buffer
        buffer[buffIndex] = (char) (97 + buffIndex);
    }
    for (; buffIndex < buffSize; buffIndex++) {
        buffer[buffIndex] = (char) (65 + buffIndex - 26); //capital alphabet into latter half of buffer
    }
    
    char key[5];
    char hash[14];
    hash[13] = '\0'; //manually adding null character
    int length;
    int firstIndex, secondIndex, thirdIndex, fourthIndex;
    for (length = 0; length < 4; length++) {
        key[length + 1] = '\0'; //manually places null character
        
        for (firstIndex = 0; firstIndex < buffSize; firstIndex++) {
            key[0] = buffer[firstIndex];
            if (length == 0) {
                strncpy(hash, crypt(key, salt), 13);
            }
            else if (length == 1) {
                for (secondIndex = 0; secondIndex < buffSize; secondIndex++) {
                    key[1] = buffer[secondIndex];
                    strncpy(hash, crypt(key, salt), 13);
                    
                    if (strncmp(hash, argv[1], 13) == 0) {
                        printf("%s\n", key);
                        return 0;
                    }
                }
            }
            else if (length == 2) {
                for (secondIndex = 0; secondIndex < buffSize; secondIndex++) {
                    key[1] = buffer[secondIndex];

                    for (thirdIndex = 0; thirdIndex < buffSize; thirdIndex++) {
                        key[2] = buffer[thirdIndex];
                        strncpy(hash, crypt(key, salt), 13);
                    
                        if (strncmp(hash, argv[1], 13) == 0) {
                            printf("%s\n", key);
                            return 0;
                        }
                    }
                }
            }
            else {
                for (secondIndex = 0; secondIndex < buffSize; secondIndex++) {
                    key[1] = buffer[secondIndex];
                    for (thirdIndex = 0; thirdIndex < buffSize; thirdIndex++) {
                        key[2] = buffer[thirdIndex];

                        for (fourthIndex = 0; fourthIndex < buffSize; fourthIndex++) {
                            key[3] = buffer[fourthIndex];
                            strncpy(hash, crypt(key, salt), 13);
                        
                            if (strncmp(hash, argv[1], 13) == 0) {
                                printf("%s\n", key);
                                return 0;
                            }
                        }
                    }
                }
            }
            
            if (strncmp(hash, argv[1], 13) == 0) {
                printf("%s\n", key);
                return 0;
            }
        }
    }
    
    return 1;
}
