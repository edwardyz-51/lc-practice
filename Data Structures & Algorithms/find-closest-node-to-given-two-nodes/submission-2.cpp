class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<bool>> seen(2, vector<bool>(n, false));

        while (node1 != -1 || node2 != -1) {
            int ans = n+1;

            if (node1 != -1 && seen[1][node1])
                ans = min(ans, node1);

            if (node2 != -1 && seen[0][node2])
                ans = min(ans, node2);

            if (node1 != -1 && node1 == node2)
                ans = min(ans, node1);

            if (ans != n+1) return ans;

            int next1 = -1, next2 = -1;

            if (node1 != -1 && !seen[0][node1]) {
                seen[0][node1] = true;
                next1 = edges[node1];
            }

            if (node2 != -1 && !seen[1][node2]) {
                seen[1][node2] = true;
                next2 = edges[node2];
            }

            node1 = next1;
            node2 = next2;
        }

        return -1;
    }
};