#include <iostream>
#include "lab02_min_switch.h"

#define HOUR 3600

bool check(int h, int m) {return h > 23 || m > 59 ? false : true;}

void print_info(int sec, int hour, int min)
{
    if (sec > 24 * 3600 - 1) printf("incorrect input");
    else if (sec % HOUR == 0)
    {
        if (sec == 0) printf("Полночь.\n");
        else if (sec == HOUR) printf("Час ночи ровно.\n");
        else if (sec == 12 * HOUR) printf("Полдень.\n");
        else if (sec >= 2 * HOUR && sec <= 4 * HOUR) printf("%d часа ночи ровно.\n", sec / HOUR);
        else if (sec >= 5 * HOUR && sec < 12 * HOUR) printf("%d часов утра ровно.\n", sec / HOUR);
        else if (sec == 13 * HOUR) printf("Час дня ровно.\n");
        else if (sec > 13 * HOUR && sec <= 17 * HOUR) printf("%d часа дня ровно.\n", (sec / HOUR) - 12);
        else if (sec >= 18 * HOUR && sec <= 23 * HOUR) printf("%d часов вечера ровно.\n", (sec / HOUR) - 12);
    } else {
        if (sec / HOUR  == 1 ) night_switch1(hour, min);
        else if (sec / HOUR > 1 && sec / HOUR < 5) night_switch(hour, min);
        else if (sec / HOUR >= 5 && sec / HOUR < 12) morning_switch(hour, min);
        else if (sec / HOUR == 12) midday_switch(hour, min);
        else if (sec / HOUR == 13) afternoon_switch1(hour - 12, min);
        else if (sec / HOUR > 13 && sec / HOUR < 17) afternoon_switch(hour - 12, min);
        else if (sec / HOUR == 17) afternoon_switch_5(hour - 12, min);
        else if (sec / HOUR >= 18 && sec / HOUR <= 23) evening_switch(hour - 12, min);
    }
}

int main()
{
    unsigned int get_h, get_m;
    scanf("%d %d", &get_h, &get_m);

    unsigned int totalsec = 0;
    if (check(get_h, get_m))
    {
        totalsec = get_h * 3600 + get_m * 60;
        print_info(totalsec, get_h, get_m);
    } else {
        printf("incorrect input");
    }

    return 0;
}
