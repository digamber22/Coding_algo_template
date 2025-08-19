// https://maang.in/contests/attempts/50809?problem_id=889

// TC -> nlogn 

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

 ll n, k ; 
 vector<ll>arr;

bool check(ll x)
{
    ll taken = 1, prev = arr[0];

    for (ll i = 1; i < n; i++)
    {
        if (arr[i] - prev >= x)
        {
            taken++;
            prev = arr[i];
        }
    }

    if (taken >= k)
        return true;

    return false;
}

void solve () {

 cin>>n>>k ;
 arr.assign(n,0);

 for(int i=0 ; i<n ; i++) cin>>arr[i];

  sort(arr.begin(), arr.end());

        ll l, u, mid, ans = 0;
        l = 0;
        u = 1e9;

        while (l <= u)
        {
            mid = (l + u) / 2;
            if (check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                u = mid - 1;
        }

        cout << ans << "\n";
    }


int main() {
 ll t ;cin>>t;
 while(t--) {
 solve() ;
 }
 
 return 0;
}