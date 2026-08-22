class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>degrees(numCourses,0);
        vector<vector<int>> prerequirees(numCourses);
        for (vector<int>& reqs : prerequisites){
            degrees[reqs[0]]++;
            prerequirees[reqs[1]].push_back(reqs[0]);
        }
        vector<int>ans;
        queue<int> queue;
        for (int i = 0; i < numCourses; ++i) if (!degrees[i]) queue.push(i);
        int taken = 0;
        while (!queue.empty()){
            int cur = queue.front(); queue.pop();
            taken++;
            ans.push_back(cur);
            for (int i : prerequirees[cur]){
                degrees[i]--;
                if (!degrees[i]) queue.push(i);
            }
        }
        return taken==numCourses ? ans : vector<int>();
    }
};
