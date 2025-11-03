#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Calculation of nCr in TC -> ((n+q) * log mod ), SC ->O(n);   , q --> queries ; 
// for calc inverse modulo any number let say a , then a and mod must be coprime ;

const ll m = 1e9 + 7;
vector<ll> fact;

void precomfactC(ll N) {
    fact.assign(N + 1, 0);
    fact[0] = 1;

    for (int i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % m;
}

ll binexp(ll b, ll e, ll m) {
    ll ans = 1;
    while (e > 0) {
        if (e & 1) ans = (ans * b) % m;
        b = (b * b) % m;                   // imp step ;
        e >>= 1;
    }
    return ans;
}

void solve() {
    ll n, r; 
    cin >> n >> r;

    ll nmrt = fact[n];
    ll deno = (fact[n - r] * fact[r]) % m;
    cout << (nmrt * binexp(deno, m - 2, m)) % m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precomfactC(1e6);          // precompute factorial -> O(n); 

    solve();
    return 0;
}
