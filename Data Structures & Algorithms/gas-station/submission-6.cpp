class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < 
            accumulate(cost.begin(), cost.end(), 0)) 
            return -1;
        int total = 0, res = 0;
        for (int i = 0; i < gas.size(); i++) {
            if (total==-1) res = i;
            total += (gas[i] - cost[i]); 
            total = total < 0 ? -1 : total;
        }
        return res;
    }
};