class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(), [](vector<int>&a,vector<int>&b) {
            double a_d = sqrt((a[0]*a[0]) + (a[1]*a[1]));
            double b_d = sqrt((b[0]*b[0]) + (b[1]*b[1]));
            return a_d<b_d;

        });
        vector<vector<int>>ans;
        ans.reserve(k);
        int i = 0;
        while (ans.size()!=k) {
            ans.push_back(points[i]);
            ++i;
        }
        return ans;
    }
};
