#include <stdio.h>

void night_switch1(int hour, int min)
{
    if (min >= 20 || min <= 10)
    {
        switch (min % 10)
            {
            case 0: 
                printf("%d час %d минут ночи.\n", hour, min);
                break;
            case 1:
                printf("%d час %d минута ночи.\n", hour, min);
                break;
            case 2:
                printf("%d час %d минуты ночи.\n", hour, min);
                break;
            case 3:
                printf("%d час %d минуты ночи.\n", hour, min);
                break;
            case 4:
                printf("%d час %d минуты ночи.\n", hour, min);
                break;
            default:
                printf("%d час %d минут ночи.\n", hour, min);
                break;
            }
    } else
    {
        printf("%d час %d минут ночи.\n", hour, min);
    }
}

void night_switch(int hour, int min)
{
    if (min >= 20 || min <= 10)
    {
        switch (min % 10)
            {
            case 0: 
                printf("%d часа %d минут ночи.\n", hour, min);
                break;
            case 1:
                printf("%d часа %d минута ночи.\n", hour, min);
                break;
            case 2:
                printf("%d часа %d минуты ночи.\n", hour, min);
                break;
            case 3:
                printf("%d часа %d минуты ночи.\n", hour, min);
                break;
            case 4:
                printf("%d часа %d минуты ночи.\n", hour, min);
                break;
            default:
                printf("%d часа %d минут ночи.\n", hour, min);
                break;
            }
    } else
    {
        printf("%d часа %d минут ночи.\n", hour, min);
    }
}


void morning_switch(int hour, int min)
{
    if (min >= 20 || min <= 10)
    {
        switch (min % 10)
            {
            case 0: 
                printf("%d часов %d минут утра.\n", hour, min);
                break;
            case 1:
                printf("%d часов %d минута утра.\n", hour, min);
                break;
            case 2:
                printf("%d часов %d минуты утра.\n", hour, min);
                break;
            case 3:
                printf("%d часов %d минуты утра.\n", hour, min);
                break;
            case 4:
                printf("%d часов %d минуты утра.\n", hour, min);
                break;
            default:
                printf("%d часов %d минут утра.\n", hour, min);
                break;
            }
    } else
    {
        printf("%d часов %d минут утра.\n", hour, min);
    }
}

void midday_switch(int hour, int min)
{
    if (min >= 20 || min <= 10)
    {
        switch (min % 10)
            {
            case 0: 
                printf("%d часов %d минут дня.\n", hour, min);
                break;
            case 1:
                printf("%d часов %d минута дня.\n", hour, min);
                break;
            case 2:
                printf("%d часов %d минуты дня.\n", hour, min);
                break;
            case 3:
                printf("%d часов %d минуты дня.\n", hour, min);
                break;
            case 4:
                printf("%d часов %d минуты дня.\n", hour, min);
                break;
            default:
                printf("%d часов %d минут дня.\n", hour, min);
                break;
            }
    } else
    {
        printf("%d часов %d минут дня.\n", hour, min);
    }
}

void afternoon_switch1(int hour, int min)
{
    if (min >= 20 || min <= 10)
    {
        switch (min % 10)
            {
            case 0: 
                printf("%d час %d минут дня.\n", hour, min);
                break;
            case 1:
                printf("%d час %d минута дня.\n", hour, min);
                break;
            case 2:
                printf("%d час %d минуты дня.\n", hour, min);
                break;
            case 3:
                printf("%d час %d минуты дня.\n", hour, min);
                break;
            case 4:
                printf("%d час %d минуты дня.\n", hour, min);
                break;
            default:
                printf("%d час %d минут дня.\n", hour, min);
                break;
            }
    } else
    {
        printf("%d час %d минут дня.\n", hour, min);
    }
}

void afternoon_switch(int hour, int min)
{
    if (min >= 20 || min <= 10)
    {
        switch (min % 10)
            {
            case 0: 
                printf("%d часа %d минут дня.\n", hour, min);
                break;
            case 1:
                printf("%d часа %d минута дня.\n", hour, min);
                break;
            case 2:
                printf("%d часа %d минуты дня.\n", hour, min);
                break;
            case 3:
                printf("%d часа %d минуты дня.\n", hour, min);
                break;
            case 4:
                printf("%d часа %d минуты дня.\n", hour, min);
                break;
            default:
                printf("%d часа %d минут дня.\n", hour, min);
                break;
            }
    } else
    {
        printf("%d часа %d минут дня.\n", hour, min);
    }
}

void afternoon_switch_5(int hour, int min)
{
    if (min >= 20 || min <= 10)
    {
        switch (min % 10)
            {
            case 0: 
                printf("%d часов %d минут дня.\n", hour, min);
                break;
            case 1:
                printf("%d часов %d минута дня.\n", hour, min);
                break;
            case 2:
                printf("%d часов %d минуты дня.\n", hour, min);
                break;
            case 3:
                printf("%d часов %d минуты дня.\n", hour, min);
                break;
            case 4:
                printf("%d часов %d минуты дня.\n", hour, min);
                break;
            default:
                printf("%d часов %d минут дня.\n", hour, min);
                break;
            }
    } else
    {
        printf("%d часов %d минут дня.\n", hour, min);
    }
}

void evening_switch(int hour, int min)
{
    if (min >= 20 || min <= 10)
    {
        switch (min % 10)
            {
            case 0: 
                printf("%d часов %d минут вечера.\n", hour, min);
                break;
            case 1:
                printf("%d часов %d минута вечера.\n", hour, min);
                break;
            case 2:
                printf("%d часов %d минуты вечера.\n", hour, min);
                break;
            case 3:
                printf("%d часов %d минуты вечера.\n", hour, min);
                break;
            case 4:
                printf("%d часов %d минуты вечера.\n", hour, min);
                break;
            default:
                printf("%d часов %d минут вечера.\n", hour, min);
                break;
            }
    } else
    {
        printf("%d часов %d минут вечера.\n", hour, min);
    }
}