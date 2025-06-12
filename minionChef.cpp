#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool TorF(vector<int>& v, long double val,ll h){
    ll sum=0;
    for(auto &x:v)
        sum+=ceil(x/val);
    
    return sum<=h;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    ll n,h;
	    cin>>n>>h;
	    vector<int> v(n);
	    for(int i=0;i<n;i++)
	        cin>>v[i];
	        
	    ll first=1, last=1e9;
	    
	    while(first<last){
	        ll mid=first+(last-first)/2;
	        
	        if(TorF(v,mid,h))
	            last=mid;
	        else
	            first=mid+1;
	    }
	    cout<<first<<endl;
	}
	return 0;
}
