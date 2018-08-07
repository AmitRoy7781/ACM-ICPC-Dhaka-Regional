#include<bits/stdc++.h>
using namespace std;

map<string,int >mp;
int res = 0;

void process()
{
    mp["JAN"] = 31;
    mp["FEB"] = 28;
    mp["MAR"] = 31;
    mp["APR"] = 30;
    mp["MAY"] = 31;
    mp["JUN"] = 30;
    mp["JUL"] = 31;
    mp["AUG"] = 31;
    mp["SEP"] = 30;
    mp["OCT"] = 31;
    mp["NOV"] = 30;
    mp["DEC"] = 31;

}

int day_update(string temp)
{
    if(temp=="SUN") return 6;
    if(temp=="MON") return 5;
    if(temp=="TUE") return 4;
    if(temp=="WED") return 3;
    if(temp=="THU") return 2;
    if(temp=="FRI") return 1;
    if(temp=="SAT") {res++;return 7;}
}
int month_days(string temp)
{
    return mp[temp];
}
int main ()
{

    process();

    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        string mon,day;
        cin>>mon>>day;
        res = 0;
        int days = month_days(mon);
        int cur = day_update(day);

        for( ;cur<=days;cur+=7)
        {
            if(cur<=days)    res++;
            if((cur+1)<=days)   res++;
        }
        printf("%d\n",res);
    }
}
