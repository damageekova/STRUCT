#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct mydate
{
    short int day;
    short int month;
    short int year;
    short int day1;
    short int month1;
    short int year1;
    short int day2;
    short int month2;
    short int year2;

} calender;

int leap(int y)
{
    return (int)((y % 4 == 0 && y% 100 != 0) || y % 400);
}

int max(int month,int year)
{
    int days[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(leap(year))days[1]=29;
    return days[month-1];
}

int date (int day,int month,int year) {
    int a = (14 - month) / 12;
    int b =year - a;
    int c = month + 12 * a - 2;
    int dn =(7000 + (day + b + b / 4 - b / 100 + b / 400 + (31 * c) / 12));
    if (dn%7 == 0) cout<<"Sunday";
    if (dn%7 == 1) cout<<"Monday";
    if (dn%7 == 2) cout<<"Tuesday";
    if (dn%7 == 3) cout<<"Wednesday";
    if (dn%7 == 4) cout<<"Thursday";
    if (dn%7 == 5) cout<<"Friday";
    if (dn%7 == 6) cout<<"Saturday";
    return 0;
    }

char* number (int day1,  int month1, int year1, int day2,  int month2, int year2){
int d,m,y;
    if(year1>year2) {
        y=year1-year2;
        if(month1>month2) {
            m=month1-month2;
            d=day1+max(month2,year2)-day2;
            if(d>max(month2,year2))d-=max(month2,year2);
            else --m;
            --y;
        } else {
            m=12-month1+month2;
            d=day2+max(month1,year1)-day1;
            if(d>max(month1,year1))d-=max(month1,year1);
            else --m;
        }
    } else {
        y=year2-year1;
        if(month1>month2) {
            m=12-month1+month2;
            d=day1+max(month2,year2)-day2;
            if(d>max(month2,year2))d-=max(month2,year2);
            else --m;
            --y;
        } else {
            m=month2-month1;
            d=max(month1,year1)-day1+day2;
            if(d>max(month1,year1))d-=max(month1,year1);
            else --m;
        }
    }
 cout <<d<< " days "<<m<< " months "<<y<< " years ";
 return 0;
}

int main (){
    cout << "Enter date: day, month, year  " ;
    cin >> calender.day>>calender.month>>calender.year;
    cout<< date(calender.day,calender.month,calender.year)<<endl;
    cout<<"Enter first date (day month year): ";
    cin>>calender.day1>>calender.month1>>calender.year1;
    cout<<"Enter second date (day month year): ";
    cin>>calender.day2>>calender.month2>>calender.year2;
    cout<< number(calender.day1,calender.month1,calender.year1,calender.day2,calender.month2,calender.year2);
    return 0;
}
