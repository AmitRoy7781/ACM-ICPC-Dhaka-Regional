#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

map<int,int> mp;

int main ()
{
    int tc,cn=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        mp.clear();
        vector<char> v;
        for(int i=1;i<=n;i++)
        {
            int temp;
            scanf("%d",&temp);
            mp[temp]++;
        }
        int now = 0;
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            if(mp[now+1])
            {
                now = now+1;
                mp[now]--;
                v.push_back('(');
            }
            else if(now>0 && mp[now-1])
            {
                now = now - 1;
                mp[now]--;
                v.push_back(')');
            }
            else
            {
                flag = false;
                break;
            }
        }
        printf("Case %d: ",cn++);
        if(flag && !now)
        {
            for(int i=0;i<v.size();i++)
            {
                printf("%c",v[i]);
            }
            printf("\n");
        }
        else
        {
            printf("invalid\n");
        }
    }
    return 0;
}
