class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t n = temperatures.size();
        vector<int>ans(n);
        stack<int>days;
        for (size_t i(0uz); i < n; ++i){
            while (!days.empty() && temperatures[days.top()] < temperatures[i]) {
                ans[days.top()] = i-days.top();
                days.pop();
            }
            days.push(i);
        }
        return ans;
    }
};
