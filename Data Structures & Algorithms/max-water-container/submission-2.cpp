class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int pointer=0;
        int twoPointer=heights.size()-1;
        while (pointer < twoPointer){
            int water = (twoPointer-pointer) * min(heights[pointer], heights[twoPointer]);
            if (water>ans) ans = water;
            if (heights[pointer] > heights[twoPointer]) {
                twoPointer--;
            } else {
                pointer++;
            }

        }
        return ans;
        


    }
};
