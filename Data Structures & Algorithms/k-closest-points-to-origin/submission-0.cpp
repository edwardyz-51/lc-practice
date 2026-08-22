class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> queue;
        for (int i = 0; i<points.size();++i){
            vector<int> &point = points[i];
            queue.push({distance({point[0],point[1]},{0,0}),i});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; ++i){
            int index = queue.top().second;
            queue.pop();
            ans.push_back(points[index]);
        }
        return ans;

    }

    double distance(pair<int,int>p1, pair<int,int>p2){
        return sqrt(pow(p1.first,2) + (pow(p1.second,2)));
    }
};
