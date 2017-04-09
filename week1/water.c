#include <stdio.h>

int main(int argc, char *argv[])
{
    int minutes, bottles;

    //prompt for minutes
    printf("Minutes: ");
    scanf("%d", &minutes);

    //computation for bottles of water
    bottles = minutes * 192 / 16;
    
    //display no. of bottles of water
    printf("Bottles: %d", bottles);
    return 0;
}
