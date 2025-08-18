//problem link - https://maang.in/contests/attempts/50684?problem_id=892

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
  ll n, k, q, i, a, b, x;
  cin >> n >> k >> q;
  vector<ll> v(n + 1), pre(n + 2, 0), dp(n);
  vector<pair<ll, ll> > suf;

  for (i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (i = 0; i < k; i++) {
    cin >> a >> b;
    pre[a] += 1;
    pre[b + 1] -= 1;
  }

  for (i = 1; i <= n; i++) {
    if (i != 0) {
      pre[i] = pre[i - 1] + pre[i];
      suf.push_back({v[i], pre[i]});
    }
  }
  sort(suf.begin(), suf.end());
  for (i = 0; i < n; i++) {
    if (i == 0)
      dp[i] = suf[i].second;
    else
      dp[i] = dp[i - 1] + suf[i].second;
  }
  for (i = 0; i < q; i++) {
    cin >> a;
    if (lower_bound(dp.begin(), dp.end(), a) != dp.end()) {
      x = lower_bound(dp.begin(), dp.end(), a) - dp.begin();
      cout << suf[x].first << " ";
    } else {
      cout << "-1 ";
    }
  }
  cout << endl;
}

int main() {
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, T;

  T = 1;
  cin >> T;

  for (i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}



