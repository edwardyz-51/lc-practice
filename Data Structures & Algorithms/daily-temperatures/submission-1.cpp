class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>temps;
        int n = temperatures.size();
        vector<int>ans(n,0);
        for (int i = 0; i < n; ++i){
            while (!temps.empty()&&temperatures[temps.top()] < temperatures[i]){
                ans[temps.top()] = i-temps.top();
                temps.pop();
            }
            temps.push(i);

        }
        return ans;
    }
};
