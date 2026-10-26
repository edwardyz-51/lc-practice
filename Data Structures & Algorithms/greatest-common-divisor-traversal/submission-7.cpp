class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }

    int find(int node) {
        return parent[node] == node
            ? node
            : parent[node] = find(parent[node]);
    }
    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return false;

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            ++rank[rootA];
        }

        return true;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 1) return true;
        DSU dsu(n);
        unordered_map<int, int> factorToIndex;
        for (size_t i{0uz}; i < n; ++i) {
            int num = nums[i];
            if (num==1) return false;

            for (int factor = 2; factor * factor <= num; ++factor) {
                if (num % factor != 0)
                    continue;

                if (factorToIndex.contains(factor))
                    dsu.unite(i, factorToIndex[factor]);
                else
                    factorToIndex[factor] = i;

                while (num % factor == 0)
                    num /= factor;
            }

            if (num > 1) {
                if (factorToIndex.contains(num))
                    dsu.unite(i, factorToIndex[num]);
                else
                    factorToIndex[num] = i;
            }
        }

        int root = dsu.find(0);
        for (size_t i{1uz}; i < n; ++i)
            if (dsu.find(i) != root)
                return false;
        return true;
    }
};