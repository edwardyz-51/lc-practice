class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>steps(cost.size()+1);
        steps[0] = 0; //cost to reach
        steps[1] = 0; //cost to reach
        //steps[2] = cost to reach step 2
        //steps[3] = cost to reach step 3
        for (int i = 2; i<cost.size()+1; ++i)
            steps[i]= min(steps[i-1]+cost[i-1],steps[i-2]+cost[i-2]);
        
        return steps[cost.size()];


    }
};
