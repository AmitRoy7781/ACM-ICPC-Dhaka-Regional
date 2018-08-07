#include<bits/stdc++.h>
using namespace std;

#define     LL      long long
#define     inf     LLONG_MAX
#define     MAX     1000007
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

struct Point
{
    int x,y;

} P[3005];

vector<LL> v[3005];

LL sqDist(Point a,Point b)
{
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int n,q,temp;
int main ()
{


    bool first = false;
    while(true)
    {
        scI(n);
        scI(q);
        if(first)
            printf("\n");
        first = true;
        if(!n && !q)break;
        for(int i=1; i<=n; i++)
        {
            scI(P[i].x);
            scI(P[i].y);
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {

                v[i].push_back(sqDist(P[i],P[j]));

            }
            sort(all(v[i]));
        }
        int res = 0;
        for(int i=1; i<=q; i++)
        {
            scI(temp);
            temp *= temp;

            for(int j=1; j<=n; j++)
            {
                res += (upper_bound(all(v[j]),temp) - v[j].begin());

            }

            printf("%0.2lf\n",(double)res/(n*1.0));
            res = 0;
        }
        for(int i=1; i<=n; i++)
            v[i].clear();
    }
    return 0;
}

