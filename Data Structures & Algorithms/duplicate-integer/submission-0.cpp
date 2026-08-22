class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>my_map;
        for (int n: nums) {
            my_map[n]++;
            if (my_map[n] > 1){
                return true;
            }
        }
        return false;
    }
};