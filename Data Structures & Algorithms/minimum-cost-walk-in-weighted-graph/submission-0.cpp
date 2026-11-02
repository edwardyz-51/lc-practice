class DSU {
    vector<int>parent,rank,cost;
public:
    DSU(int n) : parent(vector<int>(n)), rank(vector<int>(n,0)){
        ranges::iota(parent,0);
    }
    int find(int n){
        return n == parent[n] ? n : parent[n]=find(parent[n]);
    }
    bool unite(int a, int b){
        int pa = find(a), pb = find(b);
        if (pa==pb)return false;
        if (rank[pa]==rank[pb]) rank[pa]++, parent[pb]=pa;
        else if (rank[pa]>rank[pb])parent[pb]=pa;
        else parent[pa]=pb;
        return true;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        vector<int>costs(n,INT_MAX), ans;
        for (const auto& edge : edges)
            dsu.unite(edge[0], edge[1]);
        for (const auto& edge : edges)
            costs[dsu.find(edge[0])] &= edge[2];
        for (vector<int>& q : query){
            if (dsu.find(q[0])==dsu.find(q[1])) ans.push_back(costs[dsu.find(q[0])]);
            else ans.push_back(-1);
        }
        return ans;


    }
};
