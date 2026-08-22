class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(), [](vector<int>&a, vector<int>&b) {
            return a[1]-a[0]+1 < b[1]-b[0]+1;
        });
        vector<int>ans;
        ans.reserve(queries.size());
        for (int q : queries){
            bool flag = false;
            for (auto v : intervals){
                if (q >= v[0] && q<=v[1]){
                    ans.push_back(v[1]-v[0]+1);
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            ans.push_back(-1);
        }
        return ans;
    }
};
