class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> queue;
        for (int i = 0; i<points.size();++i){
            vector<int> &point = points[i];
            queue.push({sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]),i});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; ++i){
            int index = queue.top().second;
            queue.pop();
            ans.push_back(points[index]);
        }
        return ans;
    }
};
