class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < //if sum of gas is less than sum of cost, impossible
            accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int total = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]); //add the net gas from position i

            if (total < 0) { // process of elimination. if i = gas.size()-1, it has to be the starting point since all before cant
            // OR if this never goes below 0, then res is the answer!
            // imagine output >1. run through.
            // if gas[0] > 0, then we dont reset, so continue and add the net gas until we reach a negative total.
            // this shows that any station, from 0 until the station where we reach the negative total, is impossible to cycle from.
            // to be clear, at station 0 the net gas is positive, so from 0+1 to n the total will be even less than if station 0 is added, no matter whether
            // station 1 is positive or negative.
            // total is ALWAYS positive, or else it would be reset
            // so each total after station 0 is always gonna be positive, therefore every station between 0 and i is less and less as u remove 0, station 1, etc.
            // imagine 0 is positive and 1 is negative. if 0 is removed, 2 is clearly less. if 0 AND 1 are removed, since gas[0]+gas[1] must be positive or else reset, 2 is still less
                total = 0;
                res = i + 1;
            }
        }

        return res;
    }
};