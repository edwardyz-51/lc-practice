class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<int> dist (n, INT_MAX);
        vector<bool> visited(n, false);

        int node = 0;
        int res  = 0;
        int edges = 0;
        while (edges < n - 1)
        {
            visited[node] = true;
            int nextNode = -1;
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    int curr_dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    dist[i] = min(curr_dist, dist[i]);
                    if (nextNode == -1 || dist[i] < dist[nextNode])
                    {
                        nextNode = i;
                    }
                }
            }
            edges++;
            res += dist[nextNode];
            node = nextNode;
        }

        return res;
    }
};
