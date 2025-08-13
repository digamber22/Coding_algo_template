#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// dsu generally used in dynamic graph ,like graph with keep on changing;
// it gives two fn -> 1. findParent   2. Union  -> 2(a) rank , 2(b) size
// TC -> O(consant)

class DSU
{
    vector<int> rank, parent, size;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DSU ds(7);
    /*  ds.unionByRank(1,2);
       ds.unionByRank(2,3);
       ds.unionByRank(4,5);
       ds.unionByRank(6,7);
       ds.unionByRank(5,6);
   // if 3 and 7 same or not ;
   if(ds.findUPar(3)==ds.findUPar(7)){
    cout<<"same\n";
   } else {
    cout<<"not same\n";
   }
       ds.unionByRank(1,2);

    if(ds.findUPar(3)==ds.findUPar(7)){
    cout<<"same";
   } else {
    cout<<"not same";
   }
     */

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not ;
    if (ds.findUPar(3) == ds.findUPar(7)) cout<<"same\n";
    else  cout << "not same\n";
    
    ds.unionBySize(3, 7);

   if (ds.findUPar(3) == ds.findUPar(7)) cout<<"same\n";
    else  cout << "not same\n";
    
    return 0;
}