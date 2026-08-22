class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses); //idx = course, adj[idx] = all classes that need course idx
        vector<int>degrees(numCourses,0); //idx = course, degrees[idx] = number of prerequisites
        for (vector<int>& course : prerequisites){
            adj[course[1]].push_back(course[0]);
            degrees[course[0]]++;
        }
        int taken = 0;
        queue<int>schedule;
        for (int i = 0; i < numCourses; ++i){
            if (!degrees[i]) schedule.push(i);
        }
        while (!schedule.empty()){ 
            int cur = schedule.front();
            schedule.pop();
            taken++;
            for (int course : adj[cur]){
                degrees[course]--;
                if (!degrees[course]) schedule.push(course);
            }
        }
        cout << taken;
        return taken==numCourses;

    }
};
