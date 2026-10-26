class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        for (vector<string>& ticket : tickets) adj[ticket[0]].push_back(ticket[1]);
        for (auto& [source,destinations] : adj) sort(destinations.rbegin(),destinations.rend());
        vector<string>ans;
        dfs("JFK",ans,adj);
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void dfs(const string& source, vector<string>&ans, unordered_map<string,vector<string>>&adj){
        while (!adj[source].empty()){
            string dest = move(adj[source].back());
            adj[source].pop_back();
            dfs(dest,ans,adj);
        }
        ans.push_back(source);
    }
};
