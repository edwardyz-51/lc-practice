class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source==target) return 0;
        int stops = 0, n = routes.size();
        unordered_set<int>seen;
        unordered_map<int,vector<int>>adj; //adj[stop] = {routes with stop}
        for (size_t i{0uz}; i < n; ++i)
            for (int stop : routes[i]) adj[stop].push_back(i);
        queue<int>bfs; //bfs.front() == current bus stop
        bfs.push(source);
        while (!bfs.empty()){
            size_t sz = bfs.size();
            for (size_t _(0uz); _ < sz; ++_){
                int stop = bfs.front();
                bfs.pop();
                for (int route : adj[stop]){
                    for (int st : routes[route]) {
                        if (st==target) return stops+1;
                        if (!seen.contains(st)) {
                            seen.insert(st);
                            bfs.push(st);
                        }
                    }
                }
            }
            stops++;
        }
        return -1;

    }
};