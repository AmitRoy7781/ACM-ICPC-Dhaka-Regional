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


struct ques{

    int d,st,ch;
    ques(){};
    ques(int dd,int stt,char chh)
    {
        d = dd;
        st = stt;
        ch = (chh=='c');
    }
};

bool cmp (ques a,ques b)
{
    if(a.d<b.d) return true;
    return false;
}

vector<ques> leaked,nonleaked;

LL bs(int val)
{
    int lo = 0;
    int hi = nonleaked.size()-1;
    int mid;
    LL res=-1;
    while(hi>=lo)
    {
        mid = (hi+lo)>>1;
        if(val>nonleaked[mid].d)
        {
            res = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }

    }
    return res+1ll;
}
void CLEAR_ALL()
{
    leaked.clear();
    nonleaked.clear();
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
        ques temp;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int d,st;
            char ch;
            scanf("%d %d %c",&d,&st,&ch);
            temp = ques(d,st,ch);
            if(st && ch=='c')
            {
                leaked.push_back(temp);
            }
            else if(!st && ch=='i')
            {
                nonleaked.push_back(temp);
            }
        }
        sort(all(leaked),cmp);
        sort(all(nonleaked),cmp);
        LL res=0;

        for(int i=0;i<leaked.size();i++)
        {
            res = res + bs(leaked[i].d);
        }
        printf("%lld\n",res);

    }
    return 0;
}
