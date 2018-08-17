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


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int p,c,cur=0;
    string temp;
    int id,cn=1;
    vector<int> v;

    while(true)
    {

        cin>>p>>c;
        if(!p && !c)    break;

        cout<<"Case "<<cn++<<":"<<endl;
        v.clear();
        for(int i=1;i<=min(p,c);i++)
            v.push_back(i);

        cur = 0;
        for(int i=0;i<c;i++)
        {
            cin>>temp;
            if(temp=="N")
            {

                cout<<v[cur]<<endl;
                cur ++;
                cur = cur % v.size();
            }
            else
            {
                cin>>id;
                v.insert(v.begin()+cur,id);
                for(int i=0;i<v.size();i++)
                {
                    if(i!=cur && v[i]==id)
                    {
                        v.erase(v.begin()+i);

                        if(i<cur)   cur--;
                        break;
                    }
                }

            }
        }
    }
    return 0;
}

