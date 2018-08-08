
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



int main ()
{

    int tc,cn;
    scI(tc);
    while(tc--)
    {
        string s;
        cin>>s;
        int n;
        scI(n);
        map<char,char> mp;
        for(char a='A';a<='Z';a++)
            mp[a] = a;
        mp['_'] = '_';
        for(int i=0;i<n;i++)
        {
            string a,b;
            cin>>a;
            cin>>b;

            map<char,char>::iterator it;
            for(it = mp.begin();it!=mp.end();it++)
            {
                if((it->second)==b[0])
                {
                    it->second = a[0];
                }
            }
        }
        for(int i=0;i<s.size();i++)
        {
            s[i] = mp[s[i]];
        }
        printf("%s\n",s.c_str());
    }
    return 0;
}

