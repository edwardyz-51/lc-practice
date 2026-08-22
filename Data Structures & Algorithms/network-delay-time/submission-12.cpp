class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n+1,INT_MAX);
        vector<bool> visited(n+1,false);
        vector<vector<vector<int>>>adjacent(n+1); //{vi,ti} == {target node, time from source}
        for (const vector<int>& connection : times) adjacent[connection[0]].push_back({connection[1],connection[2]});
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> active;
        active.push({0,k});
        distance[k]=0;
        int time = 0, seen = 0;
        while (seen!=n){
            if (active.empty()) return -1;
            int node = active.top()[1];
            int new_t = active.top()[0];
            active.pop();
            if(visited[node]) continue;
            visited[node]=true;
            seen++;
            time=max(time,new_t);
            for (const vector<int>& adj : adjacent[node]){
                int temp_node = adj[0];
                int dt = adj[1];
                if (!visited[temp_node] && distance[temp_node] > new_t+dt){
                    distance[temp_node]=new_t+dt;
                    active.push({new_t+dt,temp_node});
                }
            }

        }
        return time;
    }
};
