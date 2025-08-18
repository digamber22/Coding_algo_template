// Link - https://codeforces.com/contest/1324/problem/D

// TC -> nlogn 

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void solve() {
    
    ll n;
    cin>>n;
 
   vector<ll>a(n),b(n),d(n);

    for(int i=0;i<n;i++) cin>>a[i];
    
    for(int i=0;i<n;i++) cin>>b[i];
    
 
    for(int i=0;i<n;i++){
        d[i]=a[i]-b[i];
    }

    sort(d.begin(),d.end());
 
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(d[i]>0){
            cnt+=n-i-1;
            continue;
        }
        auto j=upper_bound(d.begin(),d.end(),0-d[i])-d.begin();
        cnt+=n-j;
    }
 
    cout<<cnt<<endl;
}

int main() {
 ll t ;cin>>t;
 while(t--) {
 solve() ;
 }
 
 return 0;
}