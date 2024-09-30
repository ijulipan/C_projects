#include <stdio.h>

int is_leap_year(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int day_of_year(int year, int month, int day){
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year)){
        days_in_month[2] = 29; // Adjust for leap year
    }

    int day_of_year = day;
    for(int i = 1; i < month; i++){
        day_of_year += days_in_month[i];
    }

    return day_of_year;
}

int main(){
    int year, month, day;

    printf("Enter year, month and day: \n");
    scanf("%d %d %d", &year, &month, &day);

    int day_of_year_result = day_of_year(year, month, day);
    printf("This is the %d day of the year %d.\n", day_of_year_result, year);

    return 0;
}