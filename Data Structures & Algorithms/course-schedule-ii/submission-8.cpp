class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>degrees(numCourses,0);
        for (auto& course : prerequisites){
            adj[course[1]].push_back(course[0]);
            degrees[course[0]]++;
        }
        queue<int>q;
        for (int i = 0; i < numCourses; ++i) if (!degrees[i]) q.push(i);
        vector<int>ans;
        while (!q.empty()){
            int c = q.front();
            ans.push_back(c);
            q.pop();
            for (int course : adj[c]){
                degrees[course]--;
                if (degrees[course]==0) q.push(course);
            }
        }
        if (ans.size()==numCourses) return ans;
        return {};
    }
};
