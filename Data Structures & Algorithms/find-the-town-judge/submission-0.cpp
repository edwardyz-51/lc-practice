class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>degrees(n+1,0);
        vector<vector<int>>adj(n+1);
        for (auto& t : trust){
            degrees[t[1]]++;
            adj[t[0]].push_back(t[1]);
        }
        for (int i = 1; i <= n; ++i){
            if (degrees[i]==n-1 && adj[i].empty()) return i;
        }
        return -1;

    }
};