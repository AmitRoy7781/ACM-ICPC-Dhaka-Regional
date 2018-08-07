#include<bits/stdc++.h>
using namespace std;

#define     ll      long long
#define     inf     999999999999999999
#define     MAX     1000007
#define     MOD     1000000007
#define     pll     pair<ll,ll>
#define     pii     pair<int,int>
#define     eps     1e-6
#define     FIN     freopen("input.txt","r",stdin);
#define     FOUT    freopen("output.txt","w",stdout);
#define     CLR(a)  memset(a,0,sizeof(a))

bool mark[MAX],vis[MAX];
vector<int> adj[MAX],v;

void dfs(int u)
{
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++)
    {
        if(!vis[adj[u][i]])
        {
            dfs(adj[u][i]);
        }
    }
    return;
}
void CLEAR_ALL()
{
    CLR(mark);
    CLR(vis);
    for(int i=0;i<MAX;i++)
        adj[i].clear();
    v.clear();
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc,cn=1;
    scanf("%d",&tc);
    while(tc--)
    {
        CLEAR_ALL();


        int n;
        scanf("%d",&n);
        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            int temp;
            scanf("%d",&temp);
            if(temp==1)
                cnt++;
            else if( !mark[temp])
            {
                v.push_back(temp);
                mark[temp] = 1;
            }
        }
        for(int i=2;i<MAX;i++)
        {
            for(int j=i+i;j<MAX;j+=i)
            {
                if(mark[j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<v.size();i++)
        {
            if(!vis[v[i]])
                {
                    dfs(v[i]);
                    cnt++;
                }
        }
        printf("Case %d: %d\n",cn++,cnt);
    }
    return 0;
}
