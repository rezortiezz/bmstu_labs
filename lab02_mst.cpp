#include <iostream>
#include "lab02_min_switch.h"

bool check(int h, int m) {return h > 23 || m > 59 ? false : true;}

int print_info(int hour, int min)
{
    if (min == 0)
    {
        if (hour == 0) printf("Полночь.\n");
        else if (hour == 1) printf("Час ночи ровно.\n");
        else if (hour == 12) printf("Полдень.\n");
        else if (hour >= 2 && hour <= 4 ) printf("%d часа ночи ровно.\n", hour);
        else if (hour >= 5 && hour < 12) printf("%d часов утра ровно.\n", hour);
        else if (hour == 13) printf("Час дня ровно.\n");
        else if (hour > 13 && hour <= 17) printf("%d часа дня ровно.\n", hour - 12);
        else if (hour >= 18 && hour <= 23) printf("%d часов вечера ровно.\n", hour - 12);
    } else {
        if (hour  == 1 ) night_switch1(hour, min);
        else if (hour > 1 && hour < 5) night_switch(hour, min);
        else if (hour >= 5 && hour < 12) morning_switch(hour, min);
        else if (hour == 12) midday_switch(hour, min);
        else if (hour == 13) afternoon_switch1(hour - 12, min);
        else if (hour > 13 && hour < 17) afternoon_switch(hour - 12, min);
        else if (hour == 17) afternoon_switch_5(hour - 12, min);
        else if (hour >= 18 && hour <= 23) evening_switch(hour - 12, min);
    }

    return 0;
}

int main()
{
    unsigned int get_h, get_m;
    scanf("%d %d", &get_h, &get_m);
    check(get_h, get_m) ? print_info(get_h, get_m) : printf("incorrect input");
    return 0;
}
