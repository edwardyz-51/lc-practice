class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>my_map;
        for (int n: nums) {
            if (my_map.contains(n)) return true;
            my_map[n]++;
        }
        return false;
    }
};