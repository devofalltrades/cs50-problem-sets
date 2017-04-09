#include <stdio.h>

int main(int argc, char *argv[])
{
    int height = 0;
    
    while (1) {
        //prompt for height
        printf("Enter a valid height\nHeight: ");
        scanf("%d", &height);

        //check if 0-23
        if (height >= 0 && height <= 23)
            break;
    }
    
    //row and column
    int row, col;
    
    for (row = 1; row <= height; row++) {

        for (col = 1; col <= height; col++) {             
            if (col >= height - (row - 1)) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        
        //prints space between pyramids
        printf("  ");
        
        for (col = 1; col <= height; col++) {
            if (col <= row) {
                printf("#");
            }
            else {
                printf(" ");
            } 
        }
        
        //new line
        printf("\n");
    }

    return 0;
}
