#include <stdio.h>

int main(void){
    int month, day, year;
    
    printf("Please insert the date (MM/DD/YY): ");
    scanf("%d%d%d", &month, &day, &year);
    printf("The date in yyyy/mm/dd format is: %d/%02d/%02d\n", year, month, day);
    return 0;
}