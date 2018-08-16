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

    int tc,cn=1;
    cin>>tc;
    while(tc--)
    {
        string temp;
        cin>>temp;

        stack<char> st;
        int ara[30];
        CLR(ara);
        for(int i=0; temp[i]; i++)
        {
            if(st.empty())
            {
                st.push(temp[i]-'A');
                continue;
            }

            int ch = temp[i] - 'A';
            if(ch==st.top())
            {
                st.pop();
            }
            else
            {
                ara[st.top()]++;
                ara[ch]++;
                st.push(ch);
            }
        }
        cout<<"Case "<<cn++<<endl;
        for(int i=0;i<26;i++)
        {
            if(ara[i])
            {
                cout<<(char)(i + 'A')<<" = "<<ara[i]<<endl;
            }
        }
    }
    return 0;
}


