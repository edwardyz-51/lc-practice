class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0; //farthest jump possible considering only i and previous i

        for (int i = 0; i < nums.size() - 1; i++) { //[2,4,1,1,1,1]
            farthest = max(farthest, i + nums[i]); //farthest you can jump from within your range (before current end)
            
            if (i == currentEnd) { //when you reach the currentEnd (furthest you can go)
                jumps++; //jump (you have to)
                currentEnd = farthest;  //the new current end is the farthest you can go found while traversing your range.
            }
        }

        return jumps;
    }
};
