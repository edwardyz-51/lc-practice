class DSU {
    vector<int> parent, rank;
    int components;
    public:
    explicit DSU(int n) : parent(vector<int>(n)), rank(vector<int>(n,0)), components(n){
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
        components--;
        return true;
    }
    int getComponents(){
        return components;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (vector<int>&edge : edges)
            if (!dsu.unite(edge[0],edge[1])) return false;
        return dsu.getComponents()==1;
    }
};
