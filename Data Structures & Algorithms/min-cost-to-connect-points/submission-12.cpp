using point = pair<int,int>;
// {cost, idx}
// points[idx] = {xi,yi}
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<point,vector<point>,greater<>>pq;
        int ans = 0, visited = 0, N = points.size();
        pq.emplace(0,0);
        vector<bool>seen(N,false);
        while (!pq.empty()){
            auto [cost,node] = pq.top();
            pq.pop();
            if (seen[node])continue;
            seen[node]=true;
            ans+=cost, visited++;
            if (visited==N) return ans;
            for (int i = 0; i < N; ++i){
                if (i==node) continue;
                if (!seen[i]) pq.emplace(
                    abs(points[node][0] - points[i][0])+
                    abs(points[node][1] - points[i][1]), i
                );
            }
            
        }
        return ans;
    }
};
