// https://maang.in/contests/attempts/51022?problem_id=899

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll k, n ;
map<ll,ll>freq;
vector<ll>arr;

bool check(ll mid) {
     
    ll totalUsefulBalls = 0;
    for (auto v : freq)
    {
        totalUsefulBalls += min(v.second, mid);
    }
    return totalUsefulBalls >= k * mid;
}


void solve () {
 cin>>n>>k;
 arr.resize(n);

 for(int i=0 ; i<n ; i++) {
 cin>>arr[i];
 freq[arr[i]]++;
 }
 
//  ll m = freq.size();
//  if(m<k) {
//   cout<<0<<endl;
//   return ;
//  }

 ll l =0 , h = n/k, ans = 0;

 while(l<=h) {
  int mid = l+(h-l)/2;

  if(check(mid)) {
    ans = mid ;
   l = mid +1 ;
  }
  else {
   h = mid-1;
  }
 }
cout<<ans<<endl;
freq.clear();
}

int main() {
 ll t ;cin>>t;
 while(t--) {
 solve() ;
 }
 
 return 0;
}