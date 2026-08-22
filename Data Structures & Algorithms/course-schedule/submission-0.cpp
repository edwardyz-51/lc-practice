class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Count how many courses we can process
        int taken = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            taken++;

            // Reduce indegree of neighbors
            for (int next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }

        // If we took all courses, no cycle exists
        return taken == numCourses;
    }
};
