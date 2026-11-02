class DSU {
    vector<int>parent,rank;
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int N = vals.size();
    vector<vector<int>> adj(N);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<int> id(N);
    ranges::iota(id, 0);
    ranges::sort(id, [&](int a, int b) {
        return vals[a] < vals[b];
    });
    DSU dsu(N);
    int answer = N, i =0 ;
    while (i<N) {
        int j = i;
        int value = vals[id[i]];
        while (j < N && vals[id[j]] == value)
            ++j;
        //j = index in vals
        // Connect this entire value group before counting.
        for (int p = i; p < j; ++p) {
            int u = id[p];

            for (int v : adj[u]) {
                if (vals[v] <= value)
                    dsu.unite(u, v);
            }
        }

        unordered_map<int, int> count;

        for (int p = i; p < j; ++p)
            count[dsu.find(id[p])]++;

        for (auto [root, c] : count)
            answer += c * (c - 1) / 2;

        i = j;
    }

    return answer;
}
};
