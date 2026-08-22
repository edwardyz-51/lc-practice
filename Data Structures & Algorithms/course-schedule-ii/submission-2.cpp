class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses), ans;
        vector<vector<int>>dependency(numCourses);
        ans.reserve(numCourses);
        for (vector<int> course : prerequisites){
            degrees[course[0]]++;
            dependency[course[1]].push_back(course[0]);
        }
        queue<int>available;
        for (int i = 0; i < numCourses; ++i){
            if (degrees[i]==0) available.push(i);
        }

        while (!available.empty()){
            int cur = available.front();
            ans.push_back(cur);
            available.pop();
            for (int c : dependency[cur]){
                degrees[c]--;
                if (degrees[c]==0) available.push(c);
                 } 
                
            }
        
        vector<int>empty;
        return ans.size()==numCourses ? ans : empty;
    }
};
