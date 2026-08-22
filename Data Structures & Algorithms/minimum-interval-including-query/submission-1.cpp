class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        int maxEnd = intervals[intervals.size()-1][1];
        vector<int>ans, sizeMap(maxEnd+1,0);
        ans.reserve(queries.size());
        for (auto v : intervals){
            cout << sizeMap.size() << endl;
            if (v[1] > maxEnd){
                maxEnd = v[1];
                sizeMap.resize(maxEnd+1);
            }
            int length = v[1]-v[0]+1;
            for (int left = v[0]; left <= v[1]; ++left){
                if (sizeMap[left] == 0) sizeMap[left] = length;
                else sizeMap[left] = min(sizeMap[left],length);
            }
        }
        for (int q : queries){
            if (q>maxEnd || sizeMap[q] == 0) ans.push_back(-1);
            else ans.push_back(sizeMap[q]);
        }
        return ans;
    }
};
