#include<bits/stdc++.h>
using namespace std;

#define     ll      long long
#define     inf     LLONG_MAX
#define     MAX     200007
#define     MOD     10000000000007
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


ll dp[10007][10007],fact[10007];

///iterative appraoch - precalculation
void permutation()
{

    for(ll i=10000;i>=1;i--)
    {
        ll res = 1ll;
        for(ll j = 1,k=i;j<=10000;j++,k--)
        {
            res = (res*k)%MOD;
            dp[i][j] = res;
        }
    }
}

int main ()
{
    permutation();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc,cn=1;
    cin>>tc;
    while(tc--)
    {
        int l,mn,mx;
        cin>>l>>mn>>mx;
        l = l * l;
        ll res = 0;
        for(int i=mn;i<=mx;i++)
            {
                res = (res + dp[l][i])%MOD;

            }
        cout<<"Case "<<cn++<<": "<<res<<endl;
    }

    return 0;
}

