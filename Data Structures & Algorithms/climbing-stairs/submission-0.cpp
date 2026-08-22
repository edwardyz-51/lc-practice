class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps (n+1);
        steps[0] = 1; // ways to get to 0 steps
        steps[1] = 1; //ways to get to 1 step
        for (int i = 2; i<n+1; ++i){
            steps[i] = steps[i-2]+steps[i-1];
        }
        return steps[n];
        // S(n) = ways to get to step n.
        // getting to step n is either taking 1 step from step n-1 or 2 steps from step n-2
        //S(n) = S(n-2) + S(n-1)? //ways to get to step n-2 + ways to get to step n-1
    }
};
