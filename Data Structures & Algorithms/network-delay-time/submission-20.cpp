class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for (const vector<int>& time : times){
            adj[time[0]].push_back({time[2],time[1]});
            //adj[node] = {{weight,target}, ..}
        }
        vector<bool>seen(n+1,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>pq;
        int visited = 0;
        pq.push({0,k});
        while (!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            if (seen[node]) continue;
            seen[node]=true;
            visited++;
            if (visited==n) return time;
            for (auto [dt, next] : adj[node]){
                if (seen[next]) continue;
                
                int newTime = dt + time;
                pq.push({newTime,next});

            }
        }
        return -1;

    }
};
