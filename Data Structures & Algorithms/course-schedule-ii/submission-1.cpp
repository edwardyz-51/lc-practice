class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses), ans;
        ans.reserve(numCourses);
        
        for (vector<int> course : prerequisites){
            degrees[course[0]]++;
        }
        queue<int>available;
        for (int i = 0; i < numCourses; ++i){
            if (degrees[i]==0) available.push(i);
        }

        while (!available.empty()){
            int cur = available.front();
            ans.push_back(cur);
            available.pop();
            for (vector<int> course : prerequisites){
                if (course[1]==cur){
                    degrees[course[0]]--;
                    if (!degrees[course[0]]) available.push(course[0]);
                } 
                
            }
        }
        vector<int>empty;
        return ans.size()==numCourses ? ans : empty;
    }
};
