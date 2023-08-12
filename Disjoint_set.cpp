#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findUPr(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPr(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPr(u);
        int ulp_v = findUPr(v);
        if(ulp_v == ulp_u) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPr(u);
        int ulp_v = findUPr(v);
        if(ulp_v == ulp_u) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);   
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}