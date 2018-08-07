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


char ch[100007];
int res[100007];
bool open(char ch)
{
    return (ch==')' || ch=='}' || ch==']' || ch=='>');
}
bool close(char ch)
{
    return (ch=='(' || ch=='{' || ch=='[' || ch=='<');
}
bool ok(char first,char second)
{
    if(first=='(' && second==')')   return true;
    if(first=='<' && second=='>')   return true;
    if(first=='[' && second==']')   return true;
    if(first=='{' && second=='}')   return true;
    return false;
}

int main ()
{
    int tc,cn=1;
    scI(tc);
    while(tc--)
    {
        memset(res,0,sizeof(res));
        scS(ch);
        int l = strlen(ch),cnt=0,done=0;
        stack<char> st;
        stack<int> res_st;
        for(int i=l-1;i>=0;i--)
        {
            if(open(ch[i]))
            {
                st.push(ch[i]);
                res_st.push(cnt);
                cnt = 0;
                done++;
            }
            else if(close(ch[i]))
            {

                if(st.empty())
                    {
                        cnt = 0;
                        continue;
                    }
                    else if(!ok(ch[i],st.top()))
                    {
                        cnt = 0;
                        while(!st.empty())
                            st.pop();
                        while(!res_st.empty())
                            res_st.pop();
                        continue;
                    }
                    else
                    {
                        st.pop();

                        cnt += res_st.top();
                        res_st.pop();
                        cnt += 2;
                        res[i] = cnt;

                    }
            }
        }
        printf("Case %d:\n",cn++);
        for(int i=0;i<l;i++)
            printf("%d\n",res[i]);
    }
    return 0;
}


