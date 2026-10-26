class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }
    int find(int i) {
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string,int>owners;
        for (int i = 0; i < n;++i){
            for (int j = 1; j < accounts[i].size(); ++j){
                const string& email = accounts[i][j];
                if (owners.find(email)!=owners.end()) dsu.unite(owners[email],i);
                else owners[email]=i;
            }
        }
        vector<vector<string>> ans;
        unordered_map<int, vector<string>> components;
        for (auto const& [email, index] : owners) {
            int root = dsu.find(index);
            components[root].push_back(email);
        }
        for (auto&[idx,emails] : components){
            vector<string>temp = {accounts[idx][0]};
            temp.reserve(emails.size() + 1);
            sort(emails.begin(),emails.end());
            temp.insert(temp.end(),
            make_move_iterator(emails.begin()),
            make_move_iterator(emails.end()));
            ans.push_back(temp);
        }
        return ans;


    }
};