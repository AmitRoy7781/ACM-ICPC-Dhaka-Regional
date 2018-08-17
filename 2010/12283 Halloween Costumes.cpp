#include<bits/stdc++.h>
using namespace std;

#define     ll      long long
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

ll dp[107][107];
int ara[107];

ll solve(int L,int R)
{
    if(L>R) return 0;

    ll &ret = dp[L][R];
    if(ret==-1)
    {
         ret = 1+solve(L+1,R);
        for(int i=L+1;i<=R;i++)
        {
            if(ara[i]==ara[L])
            {
                ret = min(ret, solve(L+1,i)+solve(i+1,R));
            }
        }
    }
    return ret;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc,cn=1,temp;

    cin>>tc;
    while(tc--)
    {

        int n,m,j=0;
        cin>>n>>m;
        ara[0] = -1;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(temp!=ara[j])  ara[++j] = temp;
        }

        SET(dp);
        int res = solve(1,j);
        cout<<"Case "<<cn++<<": "<<res<<endl;
    }

    return 0;
}


