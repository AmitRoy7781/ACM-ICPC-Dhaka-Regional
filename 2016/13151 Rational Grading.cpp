#include<bits/stdc++.h>
using namespace std;

#define     ll      long long
#define     inf     99999999999999
#define     MAX     1000007
#define     MOD     1000000007
#define     pll     pair<ll,ll>
#define     pii     pair<int,int>
#define     eps     1e-6
#define     FIN     freopen("input.txt","r",stdin);
#define     FOUT    freopen("output.txt","w",stdout);

ll power(ll b,ll p)
{
	ll res = 1;
	while(p)
	{
		if(p&1)
			res = res * b;
		p>>=1;
		b = b * b;
	}
	return res;
}

ll convert_dec(string ch,ll b)
{
	ll p=0,ret=0,temp;
	for(int i=ch.size()-1;i>=0;i--)
	{
		if(ch[i]>='A')
			temp=ch[i] - 'A' + 10;
		else if(ch[i]>='0')
			temp=ch[i] - '0';
		ret = ret + temp*power(b,p);
		p++;
	}
	return ret;
}


int main ()
{
    string ch1;
	ll ch2;
	while(true)
    {
    	cin>>ch1>>ch2;
    	if(ch1=="0" && ch2==0)
    	{
    		break;
    	}

    	ll temp;
    	if(ch1[0]=='0' && ch1[1]=='x')
    	{
    		temp = convert_dec(ch1.substr(2),16);
    	}
    	else if(ch1[0]=='0')
    	{
    		temp = convert_dec(ch1.substr(1),8);
    	}
    	else
    	{
            if(ch1=="0")
                temp = 0;
            else
                temp = convert_dec(ch1,10);
    	}
    	long long res = 0,tmp = ch2;
    	for(int i=1;i<=tmp;i++)
    	{
    		cin>>ch1>>ch2;
    		if(ch1=="++i")
    		{
    			temp++;
    			if(temp==ch2)
    				res++;
                temp = ch2;
    		}
    		else if(ch1=="i++")
    		{
    			if(temp==ch2)
    				res++;
				temp=ch2+1;
    		}
    		else if(ch1=="--i")
    		{
    			temp--;
    			if(temp==ch2)
    				res++;
                temp = ch2;
    		}
    		else if(ch1=="i--")
    		{
    			if(temp==ch2)
    				res++;
    			temp=ch2-1;
    		}
    		else if(ch1=="i")
    		{
                if(temp==ch2)
    				res++;
                temp = ch2;
    		}
    	}
        printf("%lld\n",res );
    }
    return 0;
}
