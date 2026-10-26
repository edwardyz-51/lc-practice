class DSU {
    vector<int> parent;
    vector<int>rank;
public:
    DSU(int n){
        rank.assign(n,0);
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int node){
            return node == parent[node]? node : parent[node] = find(parent[node]);
    }
    bool unite(int a, int b){
        int rootA = find(a),rootB = find(b);
        if (rootA == rootB) return false;
        if (rank[rootA] < rank[rootB]) parent[rootA] = rootB;
        else if (rank[rootA] > rank[rootB]) parent[rootB] = rootA;
        else 
            parent[rootB] = rootA,
            rank[rootA]++;
        return true;
    }
};

class Solution {
    int kruskals(bool include, int e, int n, const vector<int>& adj, const vector<vector<int>>& edges){
        DSU dsu(n);
        int weight = 0, count = 0;
        auto lambda = [&](const vector<int>& edge){
            if (dsu.unite(edge[0],edge[1]))
                weight+=edge[2], count++;
        };
        if (include) lambda(edges[e]);
        for (int edge : adj){
            if (!include && edge==e) continue;
            lambda(edges[edge]);
            if (count==n-1) break;
        }
        return count == n-1 ? weight : -1;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int>adj(edges.size());
        iota(adj.begin(),adj.end(),0);
        ranges::sort(adj, [&](const int a, const int b){
            return edges[a][2] < edges[b][2];
        });
        int mst = kruskals(0,-1,n,adj,edges);
        vector<vector<int>>ans(2);
        for (int i = 0; i < edges.size(); ++i){
            int include = kruskals(true,i,n,adj,edges), exclude = kruskals(false,i,n,adj,edges);
            if (exclude!=mst){
                ans[0].push_back(i);
                continue;
            } 
            else if (include==mst) ans[1].push_back(i);
        }
        return ans;
    }
};