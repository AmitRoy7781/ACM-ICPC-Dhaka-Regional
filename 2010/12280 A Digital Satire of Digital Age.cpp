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

string temp;
string down[7];
string up[7];
string mid[7];
string _left[7],_right[7];
string input_left[7],input_right[7];
void process()
{
    down[0]="........";
    down[1]="........";
    down[2]=".../\\...";
    down[3]="../..\\..";
    down[4]="./....\\.";
    down[5]="/......\\"; ///characters will be written here
    down[6]="\\______/";

    up[0]=".../\\...";
    up[1]="../..\\..";
    up[2]="./....\\.";
    up[3]="/......\\";  ///characters will be written here
    up[4]="\\______/";
    up[5]="........";
    up[6]="........";

    mid[0]="........";
    mid[1]=".../\\...";
    mid[2]="../..\\..";
    mid[3]="./....\\.";
    mid[4]="/......\\"; ///characters will be written here
    mid[5]="\\______/";
    mid[6]="........";

}

void print(string left_string,string right_string,int status)
{
    if(status==1)
    {
        for(int i=0;i<7;i++)
            _left[i] = down[i];
        for(int i=0;i<7;i++)
            _right[i] = up[i];

        for(int i=0;i<left_string.size();i++)
            _left[5][i+1] = left_string[i];
        for(int i=0;i<right_string.size();i++)
            _right[3][i+1] = right_string[i];

    }
    else if(status==-1)
    {
        for(int i=0;i<7;i++)
            _left[i] = up[i];
        for(int i=0;i<7;i++)
            _right[i] = down[i];

        for(int i=0;i<left_string.size();i++)
            _left[3][i+1] = left_string[i];
        for(int i=0;i<right_string.size();i++)
            _right[5][i+1] = right_string[i];
    }
    else if(status==0)
    {
        for(int i=0;i<7;i++)
            _left[i] = mid[i];
        for(int i=0;i<7;i++)
            _right[i] = mid[i];

        for(int i=0;i<left_string.size();i++)
            _left[4][i+1] = left_string[i];
        for(int i=0;i<right_string.size();i++)
            _right[4][i+1] = right_string[i];
    }

    for(int i=0;i<7;i++)
    {
        for(int j=0;j<8;j++)
            cout<<_left[i][j];
        cout<<"||";
        for(int j=0;j<8;j++)
            cout<<_right[i][j];
        cout<<endl;
    }
}

ll char_cost(char c)
{
    ll temp = c;
    ll res = 0;
    while(temp)
    {
        if(temp&1)
            res += 500;
        else
            res += 250;
        temp>>=1;
    }
    return res;
}

ll cost(string temp)
{
    ll res = 0;
    for(int i=0;temp[i];i++)
        res += char_cost(temp[i]);
    return res;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    process();

    int tc,cn=1;
    cin>>tc;
    while(tc--)
    {
        for(int i=0;i<7;i++)
        {
            input_left[i] = "";
            input_right[i]= "";
        }

        string left_string,right_string;
        int rem1,rem2,status,actual_status;

        for(int i=0;i<7;i++)
            {
                cin>>temp;

                for(int j=0;j<8;j++)
                    {
                        input_left[i] += temp[j];
                        if(temp[j]>='A' && temp[j]<='Z')
                        {
                            left_string += temp[j];

                        }
                        if(temp[j]=='_')    rem1 = i;
                    }
                for(int j=10;j<18;j++)
                    {
                        input_right[i] += temp[j];
                        if(temp[j]>='A' && temp[j]<='Z')
                        {
                            rem2 = i;
                            right_string += temp[j];
                        }
                        if(temp[j]=='_')    rem2 = i;
                    }
            }
            cin>>temp;  ///for dummy string

            if(rem1==rem2)          status = 0;
            else if(rem1<rem2)      status = -1;
            else                    status =  1;

            if(cost(left_string)==cost(right_string))       actual_status = 0;
            else if(cost(left_string)<cost(right_string))   actual_status = -1;
            else                                            actual_status =  1;

            cout<<"Case "<<cn++<<":"<<endl;
            if(status == actual_status) cout<<"The figure is correct."<<endl;
            else
            {
                print(left_string,right_string,actual_status);
            }

    }
    return 0;
}


