// https://maang.in/contests/attempts/51022?problem_id=897
 // TC -> O(nlogn) 

 // left of dry run part
 
 #include<bits/stdc++.h>
using namespace std;
#define ll long long 
//TC -> O(nlogn) ;

void solve () {

    int N;
    
    cin>>N;
    vector<ll> h(N), w(N);
    for (int i = 0; i < N; ++i) cin >> h[i];
    for (int i = 0; i < N; ++i) cin >> w[i];

    vector<pair<ll,ll>> boxes;
    boxes.reserve(N);
    for (int i = 0; i < N; ++i) boxes.emplace_back(w[i], h[i]);

    // sort by width asc, and for equal width sort height desc
    sort(boxes.begin(), boxes.end(), [](const pair<ll,ll>& a, const pair<ll,ll>& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    // LIS (strict) on heights using patience algorithm (lower_bound)
    vector<ll> tails;
    for (auto &p : boxes) {
        ll height = p.second;
        auto it = lower_bound(tails.begin(), tails.end(), height);
        if (it == tails.end()) tails.push_back(height);
        else *it = height;
    }

    cout << (int)tails.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    while(t--) {
        solve();
    }
    return 0;
}

