class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>degree(n+1,0), outdegree(n+1,0);
        for (auto& t : trust){
            degree[t[1]]++;
            outdegree[t[0]]++;
        }
        for (int i = 1; i <= n; ++i){
            if (degree[i]==n-1 && !outdegree[i]) return i;
        }
        return -1;

    }
};