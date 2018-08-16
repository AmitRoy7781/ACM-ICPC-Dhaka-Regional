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

char ara[MAX];
int cnt[MAX][30];
void process()
{
    CLR(cnt);

    int n = strlen(ara);

    for(int i=0;i<n;i++)
        cnt[i+1][ara[i]-'a']++;

    for(int i=2;i<=n;i++)
        for(int j=0;j<26;j++)
            cnt[i][j]+=cnt[i-1][j];
}

bool isPal(int i,int j)
{

    int tot = 0,temp;
    for(int k=0;k<26;k++)
    {
        temp = cnt[j][k] - cnt[i-1][k];
        if(temp&1)  tot++;
    }
    return(tot<=1);
}

int main ()
{

    int tc,cn=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",ara);
        process();
        int res = 0;
        int n = strlen(ara);
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>=i;j--)
            {
                res+= isPal(i,j);
            }
        }
        printf("Case %d: %d\n",cn++,res);
    }
    return 0;
}


