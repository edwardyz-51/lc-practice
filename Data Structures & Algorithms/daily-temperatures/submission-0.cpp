class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>result;
        stack<int>stack;
        for (int i = 0; i<temperatures.size(); i++) {
            for (int j = i; j<temperatures.size(); j++) {
                if (temperatures[i] < temperatures[j]) {
                    result.push_back(j-i);
                    break;
                } else if (j==temperatures.size()-1) result.push_back(0);

            }
            
        }
        return result;
    }
};
