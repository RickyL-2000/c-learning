#include <stdio.h> //nica!!!!
int main()
{
    const int c = 60;
    int min, hour;
    printf("Enter minutes: \n");
    while (scanf("%d", &min)) {
        if (min<=0)
            break;
        else { 
            hour = min / c;
            min = min % c;
            printf("It's %d hours and %d minutes.\n", hour, min);
        }
    }
    return 0;
}