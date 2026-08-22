class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>degrees(numCourses,0);
        for (auto& course : prerequisites){
            adj[course[1]].push_back(course[0]);
            degrees[course[0]]++;
        }
        queue<int>q;
        for (int i = 0; i < numCourses; ++i) if (!degrees[i]) q.push(i);
        int ans = 0;
        while (!q.empty()){
            int c = q.front();
            q.pop();
            ans++;
            for (int course : adj[c]){
                degrees[course]--;
                if (degrees[course]==0) q.push(course);
            }
        }
        return ans==numCourses;
    }
};
