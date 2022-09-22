#include <stdio.h>

int print_info(int hour, int min)
{
    if (min == 0)
    {   
        if (hour == 0) printf("Полночь\n");
        else if (hour == 12) printf("Полдень\n");
        else if (hour == 1) printf("Час ночи ровно.\n");
        else if (hour >= 2 && hour <= 4 ) printf("%d часа ночи ровно.\n", hour);
        else if (hour >= 5 && hour < 12) printf("%d часов утра ровно.\n", hour);
        else if (hour == 13) printf("Час дня ровно.\n");
        else if (hour > 13 && hour < 17) printf("%d часа дня ровно.\n", hour - 12);
        else if (hour == 17) printf("5 часов дня ровно.\n");
        else if (hour >= 18 && hour <= 23) printf("%d часов вечера ровно.\n", hour - 12);
    } else {
        if ((hour > 12 ? hour - 12 : hour) == 1) printf("%d час ", hour > 12 ? hour - 12 : hour);
        else if (2 <= (hour > 12 ? hour - 12 : hour) && (hour > 12 ? hour - 12 : hour) <= 4) printf("%d часа ", (hour > 12 ? hour - 12 : hour));
        else printf("%d часов ", (hour > 12 ? hour - 12 : hour));

        if (min % 10 == 1) printf("%d %s", min,(min == 11 ? "минут" : "минута"));
        else if (2 <= min % 10 && min % 10 <= 4) printf("%d %s", min,  (min <= 20 ? "минут" : "минуты"));
        else printf("%d минут", min);

        if (0 <= hour && hour < 5) printf(" ночи.\n"); 
        else if (5 <= hour && hour < 12) printf(" утра.\n");
        else if (12 <= hour && hour < 18) printf(" дня.\n");
        else printf(" вечера\n");
    }
    return 0;
}

int main()
{
    unsigned int get_h, get_m;
    while (1)
    {
        scanf("%d %d", &get_h, &get_m);
        (get_h <= 23 && get_m <= 59) ? print_info(get_h, get_m) : printf("Введены неверные данные\n");
    }
    return 0;
}
