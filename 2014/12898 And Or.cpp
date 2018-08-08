#include<bits/stdc++.h>
using namespace std;

#define     LL      long long
#define     inf     LLONG_MAX
#define     MAX     200007
#define     MOD     1000000007
#define     pll     pair<LL,LL>
#define     pii     pair<int,int>
#define     eps     1e-11
#define     FIN     freopen("input.txt","r",stdin);
#define     FOUT    freopen("output.txt","w",stdout);

#define     all(a)  a.begin(),a.end()
#define     CLR(a)  memset(a,0,sizeof(a))
#define     SET(a)  memset(a,-1,sizeof(a))

#define     scI(a)  scanf("%d",&a)
#define     scL(a)  scanf("%lld",&a)
#define     scD(a)  scanf("%lf",&a)
#define     scC(a)  scanf("%c",&a)
#define     scS(a)  scanf("%s",a)

#define     prI(a)  printf("%d",a)
#define     prL(a)  printf("%lld",a)
#define     prD(a)  printf("%lf",a)
#define     prC(a)  printf("%c",a)
#define     prS(a)  printf("%s",a)

int cn;
string to_binary(LL a)
{
    string ret;

    while(a)
    {
        if(a&1)
        {
            ret+='1';
        }
        else
        {
            ret+='0';
        }
        a>>=1;
    }
    reverse(all(ret));
    return ret;
}
LL to_decimal(string a)
{
    LL ret = 0,b=1;
    for(int i=a.size()-1; i>=0; i--)
    {
        if(a[i]=='1')
            ret += b;
        b<<=1;
    }
    return ret;
}
void solve(string a,string b)
{
    if(a.size()<b.size())
    {
        for(int i=a.size()+1; i<=b.size(); i++)
            a = "0"+a;

    }
    else if(a.size()>b.size())
    {
        for(int i=b.size()+1; i<=a.size(); i++)
            b = "0"+b;
    }

    string OR,AND;
    int i=0;
    for(i=0; i<a.size(); i++)
    {
        if(a[i]==b[i])
        {
            OR+=a[i];
            AND+=a[i];
        }
        else
            break;
    }
    for(int j=i;j<a.size();j++)
    {
        OR+='1';
        AND+='0';
    }
    LL oo =  to_decimal(OR);
    LL aa = to_decimal(AND);
    printf("Case %d: %lld %lld\n",cn++,oo,aa);

}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cn=1;
    scI(tc);

    while(tc--)
    {
        LL a,b;
        scL(a);
        scL(b);
        string aa = to_binary(a);
        string bb = to_binary(b);

        solve(aa,bb);
    }
    return 0;
}


