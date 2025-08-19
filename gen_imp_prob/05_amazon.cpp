// https://leetcode.com/problems/regular-expression-matching/description/

#include <bits/stdc++.h>
using namespace std;

// TC -> o(n*m) ;
struct Solver {
    string s, p;
    int n, m;
    
    vector<vector<int>> dp;

    int dfs(int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];

        // if pattern consumed, match iff string also consumed
        if (j == m) return dp[i][j] = (i == n);

        // does current char match (if any char left in s)?
        bool firstMatch = (i < n) && (s[i] == p[j] || p[j] == '.');

        // if next pattern char is '*', two choices:
        // 1). use zero occurences of p[j]  -> dfs(i, j+2)
        // 2). use one+ occurences if firstMatch -> dfs(i+1, j)
        if (j + 1 < m && p[j + 1] == '*') {
            return dp[i][j] = (dfs(i, j + 2) || (firstMatch && dfs(i + 1, j)));
        }

        // otherwise, chars must match and both advance
        return dp[i][j] = (firstMatch && dfs(i + 1, j + 1));
    }

    bool isMatch(string _s, string _p) {
        s = _s; p = _p;
        n = (int)s.size(); m = (int)p.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return dfs(0, 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        string s, p;
        cin >> s >> p;
        Solver solver;
        cout << (solver.isMatch(s, p) ? "Y\n" : "N\n");
    }
    return 0;
}


/* Tabulation 

#include <bits/stdc++.h>
using namespace std;
     bool isMatch(string s, string p) {

        int n=s.length(),m=p.length();
        int dp[n+1][m+1];

        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){

                if(i==n&&j==m){
                    dp[i][j]=1;
                }
                    else if(i==n){
                    if(j<=m-2&&p[j+1]=='*')dp[i][j]=dp[i][j+2];
                    else dp[i][j]=0;
                }
                    else if(j==m){
                    dp[i][j]=0;
                }
                    else{
                    int mm = ((s[i]==p[j])||(p[j]=='.'));
                    if(j<=m-2&&p[j+1]=='*'){
                        dp[i][j]=(dp[i][j+2]||(mm&&dp[i+1][j]));
                    }else
                    {
                        dp[i][j]=mm&&dp[i+1][j+1];
                    }
                }
            }
        }
        return dp[0][0];
    }
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int testcases;
    cin>>testcases;
    while(testcases--){
        string s,p;
        cin>>s>>p;
        if(isMatch(s,p))
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
}


*/