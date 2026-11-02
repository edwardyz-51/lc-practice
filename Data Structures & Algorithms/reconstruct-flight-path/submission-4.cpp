class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        for (vector<string>& ticket : tickets)
            adj[ticket[0]].push_back(ticket[1]);
        for (auto& [t,d] : adj) ranges::sort(d,greater{});
        vector<string>ans;
        auto dfs = [&](this auto&& self, const string& ticket)->void{
            while (!adj[ticket].empty()){
                string tmp = move(adj[ticket].back());
                adj[ticket].pop_back();
                self(tmp);
            }
            ans.push_back(ticket);

        };
        dfs("JFK");
        ranges::reverse(ans);
        return ans;
    }
};
