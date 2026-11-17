class DSU {
    vector<int> parent, rank;
    public:
    explicit DSU(int n) : parent(vector<int>(n)), rank(vector<int>(n,0)) {
        ranges::iota(parent,0);
    }

    int find (int n) {
        return n == parent[n] ? n : parent[n] = find(parent[n]);
    }

    bool unite (int a, int b){
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;
        if (rank[pa] < rank[pb]) swap(pa,pb);
        if (rank[pa] == rank[pb]) rank[pa]++;
        parent[pb] = pa;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans;
        DSU dsu(n+1);
        for (const vector<int>& edge : edges)
            if (!dsu.unite(edge[0],edge[1])) 
                ans = edge;
        return ans;
    }
};
