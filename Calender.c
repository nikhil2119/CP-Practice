#include <stdio.h>

int main()
{
    int year, month, daysInMonth, startingDay;

    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);

    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30;
    else
        daysInMonth = 31;

    int yearStart = year - (14 - month) / 12;
    int x = yearStart + yearStart/4 - yearStart/100 + yearStart/400;
    int monthStart = month + 12 * ((14 - month) / 12) - 2;
    startingDay = (1 + x + (31*monthStart)/12) % 7;

    printf("\n      %d/%d\n", month, year);
    printf(" Su Mo Tu We Th Fr Sa\n");

    int day, i;
    for (i = 0; i < startingDay; i++)
        printf("   ");
    for (day = 1; day <= daysInMonth; day++)
    {
        printf("%3d", day);
        if (++i > 6)
        {
            i = 0;
            printf("\n");
        }
    }
    if (i != 0)
        printf("\n");

    return 0;
}
