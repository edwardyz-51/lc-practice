class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>map;
        for (int i = 0; i < numbers.size(); i++){
            int temp = target - numbers[i];
            if (map.count(temp)) {
                return {map[temp], i + 1};
            }
            map[numbers[i]] = i + 1;
        }
        return {};
    }
};
