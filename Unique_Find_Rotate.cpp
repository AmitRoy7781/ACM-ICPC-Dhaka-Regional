#include<bits/stdc++.h>
using namespace std;
 
 
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
 
// typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;
 
 
typedef long long       ll;
 
#define     all(a)  a.begin(), a.end()
#define     pb      push_back
#define     ff      first
#define     ss      second
 
#define     inf     (1000000000)
#define     infl    (1000000000000000000LL)
#define     MAX     200007
#define     MOD     1000000007
#define     eps     1e-6
#define     FIN     freopen("input.txt","r",stdin);
#define     FOUT    freopen("output.txt","w",stdout);
#define     SET(a)  memset((a), -1, sizeof(a))
#define     CLR(a)  memset((a), 0, sizeof(a))
#define     dbg(x)  cout << #x << " = " << x << endl
 
//pos is 0 based
inline bool checkBit(ll mask, int pos) { return  (bool)(mask & (1ll << pos));}
inline ll setBit(ll mask, int pos) {    return  (mask | (1ll << pos));}
inline ll resetBit(ll mask, int pos) {    return  (mask & ~(1ll << pos));}
inline ll toggleBit(ll mask, int pos) {    return  (mask ^ (1ll << pos));}


int main()
{
	vector<int> v;
	v = {1,2,3,5,0,6,6,7,8,9,0,1,3,4,6,2,1,3,1,4};


	//find element index
	int idx = find(all(v),0) - v.begin();
	cout<<idx<<endl;

	//cnt element
	int cnt = count(all(v),6);
	cout<<cnt<<endl;

	//remove duplicate
	sort(all(v));
	v.erase(unique(all(v)),v.end());

	for(auto it : v)
	{
		cout<<it<<" ";
	}
	cout<<endl;

	

	//rotate vector
	rotate(v.begin(),v.begin()+5,v.end());

	for(auto it : v)
	{
		cout<<it<<" ";
	}
	cout<<endl;
}
