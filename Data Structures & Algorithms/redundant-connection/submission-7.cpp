class DSU {
    vector<int>rank;
    vector<int>parent;
    public:
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n,0);
    }
    int find(int n){
        return n == parent[n] ? n : parent[n] = find(parent[n]);
    } 
    bool unite (int a, int b){
        int pa = find(a), pb = find(b);
        if (pa==pb) return false;
        if (rank[pa]==rank[pb]){
            parent[pb]=pa;
            rank[pa]++;
        } else if (rank[pa]>rank[pb]) parent[pb]=pa;
        else parent[pa]=pb;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        vector<int> ans;
        for (auto &e : edges)
            if (!dsu.unite(e[0]-1,e[1]-1)) ans = e;
        return ans;
    }
};











