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


int main ()
{
    int tc,cn=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,cnt[165];
        CLR(cnt);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int temp;
            scanf("%d",&temp);
            cnt[temp]++;
        }
        for(int i=1;i<=160;i++)
            cnt[i]+=cnt[i-1];
        int res=INT_MAX,a,b,c;
        for(int i=0;i<=160;i++)
        {
            for(int j=i+1;j<160;j++)
            {
                for(int k=j+1;k<160;k++)
                {
                    int temp = abs(n-4*cnt[i]) + abs(n-4*(cnt[j]-cnt[i])) + abs(n-4*(cnt[k]-cnt[j])) + abs(n-4*(cnt[160]-cnt[k]));
                    if(temp<res)
                    {
                        res = temp;
                        a = i;
                        b = j;
                        c = k;
                    }
                }
            }
        }
        printf("Case %d: %d %d %d\n",cn++,a,b,c);
    }

    return 0;
}


