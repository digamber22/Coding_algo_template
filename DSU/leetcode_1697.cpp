#define ll long long

class DSU {
    vector<int> rank, parent, size;

public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        int m = queries.size();
        DSU ds(n);

        vector<pair<ll, pair<int, int>>> vx; // edges
        vector<pair<ll, pair<int, int>>> qx; // queries with idx

        for (auto it : edgeList) {
            int u = it[0], v = it[1];
            ll dis = it[2];
            vx.push_back({dis, {u, v}});
        }

        sort(vx.begin(), vx.end());

        // for (int i = 0; i < m; i++) {
        //     int p = queries[i][0], q = queries[i][1];
        //     ll limit = queries[i][2];
        //     qx.push_back({limit, {p, q}});

        // }

        // pair with index: (limit, (p, q, idx))
        vector<tuple<ll, int, int, int>> sortedQueries;
        for (int i = 0; i < m; i++) {
         sortedQueries.push_back( {(ll)queries[i][2], queries[i][0], queries[i][1], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<bool> ans(m, false);
        int edgeIdx = 0;

        for (auto& t : sortedQueries) {
            ll limit;
            int p, q, idx;
            tie(limit, p, q, idx) = t;          // imp

            while (edgeIdx < vx.size() && vx[edgeIdx].first < limit) {
                int u = vx[edgeIdx].second.first;
                int v = vx[edgeIdx].second.second;
                ds.unionBySize(u, v);
                edgeIdx++;
            }

            if (ds.findUPar(p) == ds.findUPar(q)) {
                ans[idx] = true;
            }
        }

        return ans;
    }
};
