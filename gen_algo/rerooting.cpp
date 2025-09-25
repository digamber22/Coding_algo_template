// https://leetcode.com/problems/sum-of-distances-in-tree/     Leetcode 894

class Solution {
public:
// TC -> O(logW⋅(E+V)logV)  , SC ->O(v+e) ;  
    int n;
    int dfs1(int node, int parent, vector<vector<int>>& adj, int depth,
             vector<int>& cnt, vector<int>& sub) {
        sub[node] = 1;
        cnt[0] += depth;
        for (int child : adj[node]) {
            if (child != parent) {
                dfs1(child, node, adj, depth + 1, cnt, sub);
                sub[node] += sub[child];
            }
        }
        return sub[node];
    }

    void dfs2(int node, int parent, vector<vector<int>>& adj, vector<int>& cnt,
              vector<int>& sub) {
        for (int child : adj[node]) {
            if (child != parent) {
                cnt[child] = cnt[node] - sub[child] + (n - sub[child]);
                dfs2(child, node, adj, cnt, sub);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        vector<int> cnt(n, 0), sub(n, 0);
        vector<vector<int>> adj(n);
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1, adj, 0, cnt, sub);
        dfs2(0, -1, adj, cnt, sub);

        return cnt;
    }
};

