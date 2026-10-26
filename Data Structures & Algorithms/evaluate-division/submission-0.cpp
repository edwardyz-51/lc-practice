class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for (size_t i(0uz); i < equations.size(); ++i){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> ans(queries.size());
        for (size_t i(0uz); i < queries.size(); ++i){
            string a = queries[i][0], b = queries[i][1];
            queue<pair<string,double>>bfs;
            bfs.push({a,1});
            unordered_set<string>seen;
            seen.insert(a);
            bool flag = false;
            while (!bfs.empty()){
                size_t sz = bfs.size();
                for (size_t _(0uz); _ < sz; ++_){
                    auto [c,cur] = bfs.front();
                    bfs.pop();
                    for (auto[d,v] : adj[c]){
                        if (d==b){
                            ans[i]=(cur * v);
                            flag = true;
                            break;
                        }
                        if (!seen.contains(d)){
                            seen.insert(d);
                            bfs.push({d, cur * v});
                        }
                    }
                }
            }
            if (!flag) ans[i]=-1;
        }
        return ans;

    }
    // a/b=x
    // b/a = 1/x

    //a/c
    // a/b = x
    // b/c = y
    // a/c = a/b * b/c
};