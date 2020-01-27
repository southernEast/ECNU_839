#include <stdio.h>

int leap(int y);
long date_convert(long ymd);

int main()
{
    long ymd = 0;
    scanf("%ld", &ymd);
    printf("%ld", date_convert(ymd));
    return 0;
}
//
//long date_convert(long ymd)
//{
//    long year, month, day, ans = 0;
//    year = ymd / 10000;
//    month = (ymd % 10000) / 100;
//    day = ymd % 100;
//    printf("%ld %ld %ld\n", year, month, day);
//    if(leap(year))          //是闰年
//    {
//        //month
//        switch(month)
//        {
//            default: printf("nothing");
//            case 12: ans += 30;
//            case 11: ans += 31;
//            case 10: ans += 30;
//            case  9: ans += 31;
//            case  8: ans += 31;
//            case  7: ans += 30;
//            case  6: ans += 31;
//            case  5: ans += 30;
//            case  4: ans += 31;
//            case  3: ans += 29;
//            case  2: ans += 31;
//            case  1: ans = ans;       // no break
//        }
//    }
//    else          //不是闰年
//    {
//        //month
//        switch(month)
//        {
//            default: printf("nothing");
//            case 12: ans += 30;
//            case 11: ans += 31;
//            case 10: ans += 30;
//            case  9: ans += 31;
//            case  8: ans += 31;
//            case  7: ans += 30;
//            case  6: ans += 31;
//            case  5: ans += 30;
//            case  4: ans += 31;
//            case  3: ans += 28;
//            case  2: ans += 31;
//            case  1: ans = ans;       // no break
//        }
//    }
//    ans += day;
//    ans = ans + (year * 1000);
//    return ans;
//}

int leap(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return 1; /* leap */
    else
        return 0; /* no leap */
}

long date_convert(long ymd)                                     // K&R P96
{
    long year, month, day;
    int isleap;
    long leapdays[2][13] =
    {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    year = ymd / 10000;
    month = ymd / 100 % 100;
    day = ymd % 100;
    isleap = leap(year);
    for(int i = 1; i < month; ++i)
        day += leapdays[isleap][i];

    return year * 1000 + day;
}
