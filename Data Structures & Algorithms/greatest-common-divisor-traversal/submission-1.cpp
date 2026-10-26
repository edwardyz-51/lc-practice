class DSU {
    vector<int>parent, rank;
public:
    DSU(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        rank.assign(n,0);
    }
    int find (int node){
        return parent[node]==node ? node : parent[node]=find(parent[node]);
    }
    bool unite(int a, int b){
        int rootA= find(a), rootB=find(b);
        if (rootA==rootB) return false;
        if (rank[rootA]==rank[rootB])
            rank[rootA]++,
            parent[rootB] = rootA;
        else if (rank[rootA]>rank[rootB]) parent[rootB]=rootA;
        else parent[rootA]=rootB;
        return true;
    }
};
class Solution {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        size_t n = nums.size();
        DSU dsu(n);
        for (size_t i{0uz}; i < n; ++i){
            for (size_t j = i+1; j < n; ++j){
                if (gcd(nums[i],nums[j])>1) dsu.unite(i,j);
            }
        }
        int root = dsu.find(0);
        for (size_t i{1uz}; i < n; ++i) {
            if (dsu.find(i) != root)
            return false;
        }
        return true;

    }
};