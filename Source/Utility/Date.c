#include "CommonIO/BasicIO.h"
#include "Date.h"
#include <time.h>

void currentDate(Date* date) {

    const time_t nowInSeconds = time(0);
    struct tm* now = localtime(&nowInSeconds);

    date->year = now->tm_year + 1900;
    date->month = now->tm_mon + 1;
    date->day = now->tm_mday;
    date->hour = now->tm_hour;
    date->minute = now->tm_min;

}

long long dateToLongLong(const Date* date) {

    long long result;

    result = date->year * 100;
    result = (result + date->month) * 100;
    result = (result + date->day) * 100;
    result = (result + date->hour) * 100;
    result += date->minute;

    return result;

}

void longLongToDate(long long value, Date* date) {

    date->minute = value % 100;
    value /= 100;

    date->hour = value % 100;
    value /= 100;

    date->day = value % 100;
    value /= 100;

    date->month = value % 100;
    value /= 100;

    date->year = (int)value;

}

void printDate(const Date* date) {
    printf("%02d.%02d.%04d %02d:%02d", date->day, date->month, date->year, date->hour, date->minute);
}
