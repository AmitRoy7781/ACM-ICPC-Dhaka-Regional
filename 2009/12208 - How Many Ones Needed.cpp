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


ll dp[35][35][5];
string st;
ll solve(int idx,int ones,int strict)
{
    if(idx==st.size())
        return ones;

    ll &ret = dp[idx][ones][strict];

    if(ret==-1)
    {
        if(strict)
        {
            ll x = solve(idx+1,ones+1,strict);
            ll y = solve(idx+1,ones,strict);
            ret = x + y;
        }
        else
        {
            if(st[idx]=='0')
            {
                ret = solve(idx+1,ones,strict);
            }
            else
            {
                ll x = solve(idx+1,ones+1,strict);
                ll y = solve(idx+1,ones,1);
                ret = x + y;
            }
        }
    }
    return ret;
}

void process(ll a)
{
    st = "";
    while(a)
    {
        if(a&1)
            st = "1" + st;
        else
            st = "0" + st;
        a>>=1;
    }
    return;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a,b,res,cn=1;
    while(true)
    {
        cin>>a>>b;
        if(!a && !b)    return 0;

        process(a);
        //cout<<st<<endl;
        SET(dp);
        ll up = solve(0,0,false);
        //cout<<up<<endl;

        process(b);
        //cout<<st<<endl;
        SET(dp);
        ll down = solve(0,0,false);
        //cout<<down<<endl;

        //cout<<up<<endl;
        //cout<<down<<endl;

        res = __builtin_popcount(a) + down - up;
        cout<<"Case "<<cn++<<": "<<res<<endl;

    }
    return 0;
}


