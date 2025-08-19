//  https://maang.in/contests/attempts/50809?problem_id=888

// TC -> O(n) ;

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 998224353

// TC -> o(N) 


ll  binpow(ll  a, ll  b)
{
    a %= mod;
    ll  res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll  process(stack<int> st, string op)
{
    ll  a, b, ans = 0;
    a = st.top();
    st.pop();
    b = st.top();
    st.pop();

    if (op == "+")
    {
        ans = ((a + b) % mod + mod) % mod;
    }
    else if (op == "-")
    {
        ans = ((b - a) % mod + mod) % mod;
    }
    else if (op == "*")
    {
        ans = ((a * b) % mod + mod) % mod;
    }
    else
    {
        ans = ((b * binpow(a, mod - 2)) % mod + mod) % mod;
    }

    return ans;
}

void solve () {
  int n, i, ans = 0;
        cin >> n;

        vector<string> tokens;
        tokens.resize(n);

        for (i = 0; i < n; i++)
        {
            cin >> tokens[i];
        }

        stack<int> st;

        if (n == 1)
        {
            cout << stoi(tokens[0]) << "\n";
            return ;
        }

        for (i = 0; i < n; i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                ans = process(st, tokens[i]);
                st.pop();
                st.pop();
                st.push(ans);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
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