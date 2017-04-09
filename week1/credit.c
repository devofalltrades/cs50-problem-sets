#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_int_length(long long pLong);
int isolate(long long pCred, int pIndex);
void validate(long long pCred); 

int main()
{
    long long credit;

    printf("Number: ");
    scanf("%lli", &credit);

    validate(credit);

    return 0;
}

int get_int_length(long long pLong) {
    int length = 0;

    if (pLong != 0) {
        length = floor(log10(llabs(pLong))) + 1; 
    }
    else {
        length = 1;
    }

    return length;
}

int isolate(long long pCred, int pIndex) {
    long long topFilter = powl(10, pIndex + 1);
    long long topFilterValue = 0;
    long long bottomFilter = (powl(10, pIndex));
    int isolate = 0;
    
    if (topFilter < pCred) {
        topFilter = pCred / topFilter * topFilter; //gets the value to subtract from credit number to remove top part of credit num
        topFilterValue = pCred - topFilter;
        isolate = topFilterValue / bottomFilter;
    }
    else {
        isolate = pCred / bottomFilter;
    }

    return isolate;
}

void validate(long long pCred) {
    int sumOfDoubled = 0;
    int sumOfLeftovers = 0;
    int doubled = 0;
    int doubledLength = 0;
    int lengthOfCred = get_int_length(pCred);
    int currIsolate = 0;

    for (int index = 0; index < lengthOfCred; index++) {
        currIsolate = isolate(pCred, index);
        
        if ((index + 1) % 2 == 0) {
            doubled = currIsolate * 2;
            doubledLength = get_int_length(doubled);
            for (int dIndex = 0; dIndex < doubledLength; dIndex++) {
                sumOfDoubled += isolate(doubled, dIndex);
            }
        } 
        else {
            sumOfLeftovers += currIsolate;
        }
    }

    if ((sumOfLeftovers + sumOfDoubled) % 10 == 0) {
        switch (lengthOfCred) {
            case 13:
                printf("VISA\n");
                break;
            case 15:
                printf("AMEX\n");
                break;
            case 16:
                if (isolate(pCred, lengthOfCred - 1) == 4) {
                    printf("VISA\n");
                }
                else {
                    printf("MASTERCARD\n");
                }
                break;
        }
    }
    else {
        printf("INVALID\n");
    }

}    
