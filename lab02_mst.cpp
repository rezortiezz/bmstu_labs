#include <iostream>
#include <vector>
#include "lab02_min_switch.h"

#define MAXLEN 6
#define HOUR 3600

int get_hour_24f(std::vector<int> h)
{
	int h_size = h.size();
	if (h_size == 1)
	{
		return h[0];
	} else {
		if (h[0] == 0) return h[1];
		else return h[0] * 10 + h[1];
	}
}

int get_minutes(std::vector<int> m)
{
	if (m[0] == 0) return m[1];
	else return m[0] * 10 + m[1];
}

bool check(int h, int m)
{
    if (h > 23 || m > 59) return false;
    else return true; 
}

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
        //printf("%d\n", sec / HOUR);
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
    char user_input[MAXLEN];
    fgets(user_input, MAXLEN, stdin);

    std::vector<int> hours;
    std::vector<int> minutes;
    unsigned int totalsec = 0;
    bool flag = false;

    for (int i = 0; i < MAXLEN; i++)
    {
        if (user_input[i] == ' ')
		{
			flag = true;
			continue;
		}
		if (!flag) hours.push_back(int(user_input[i] - 48));
		else minutes.push_back(int(user_input[i] - 48));
    }
    int i_hours = get_hour_24f(hours), i_minutes = get_minutes(minutes);
    if (check(i_hours, i_minutes))
    {
        totalsec = get_hour_24f(hours) * 3600 + get_minutes(minutes) * 60;
        print_info(totalsec, i_hours, i_minutes);
    } else {
        printf("incorrect input");
    }
    
    return 0;
}
