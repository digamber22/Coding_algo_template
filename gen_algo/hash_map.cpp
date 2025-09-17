// https://leetcode.com/problems/shortest-palindrome/description/

class Solution {
public:
 // method  5 , TC -> O(N)
  // this is rolling hash variant, 
    int longestPrefixPalindrome(string const& s) {
        const int p = 31, m = 1e9 + 9;
        int n = s.size();
        long long h1 = 0, h2 = 0, p_pow = 1;
        int best = 0;
        for (int i = 0; i < n; i++) {
            // forward hash (prefix)
            h1 = (h1 * p + (s[i] - 'a' + 1)) % m;
            // backward hash (suffix from start)
            h2 = (h2 + (s[i] - 'a' + 1) * p_pow) % m;
            if (h1 == h2) best = i + 1;
            p_pow = (p_pow * p) % m;
        }
        return best;
    }

    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return s;

        int len = longestPrefixPalindrome(s);
        string add = s.substr(len);  // Pos(len) to end .
        reverse(add.begin(), add.end());
        return add + s;
    }
};


// method 4 kMP Variance   , TC -> O(n);

class Solution {
public:
// TC -> O(n) , kmp variant , method 3 
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string comb = s + "#" + rev;

        // compute prefix function
        int n = comb.size();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && comb[i] != comb[j]) j = pi[j - 1];
            if (comb[i] == comb[j]) j++;
            pi[i] = j;
        }

        int len = pi.back(); // longest palindrome prefix
        string add = s.substr(len);
        reverse(add.begin(), add.end());
        return add + s;
    }
};

