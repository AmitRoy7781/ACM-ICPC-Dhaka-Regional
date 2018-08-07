#include<bits/stdc++.h>
using namespace std;

int ara[]={1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
47045881, 64000000 ,85766121};
map<int,int> mp;
int main ()
{
    for(int i=0;i<=20;i++)
        mp[ara[i]]=1;
    int temp;
    while(true)
    {
        scanf("%d",&temp);
        if(!temp)   break;
        if(mp[temp])
            printf("Special\n");
        else
            printf("Ordinary\n");
    }
    return 0;
}
