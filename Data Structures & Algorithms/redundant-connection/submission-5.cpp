class Solution {
public:

    vector<int> parent;
    vector<int> rank_;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();          // nodes are 1..n
        parent.resize(n + 1);
        rank_.assign(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);

        vector<int> ans;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (!unite(u,v)) ans = e;
        }
        return ans;
    }


    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
        return true;
    }
};











