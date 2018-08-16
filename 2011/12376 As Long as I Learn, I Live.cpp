
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc,cost[107],next_node[107],cn=1;
    cin>>tc;

    while(tc--)
    {
        int n,m;
        SET(next_node);

        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>cost[i];
        for(int j=0;j<m;j++)
        {
            int u,v;
            cin>>u>>v;
            if(next_node[u]==-1 || cost[next_node[u]]<cost[v])
                next_node[u] = v;
        }
        int cur = 0,res=0;
        while(next_node[cur]!=-1)
        {
            cur = next_node[cur];
            res += cost[cur];
        }
        cout<<"Case "<<cn++<<": "<<res<<" "<<cur<<endl;
    }
    return 0;
}

