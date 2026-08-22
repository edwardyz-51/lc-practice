class Solution {
public:
    int bSearch(vector<int>&nums,int l, int r, int t){
        while (l<=r){
            int m = (l+r)/2;
            if (nums[m]<t) l=m+1;
            else if (nums[m]>t) r=m-1;
            else return m;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); ++i){
            int t = target-numbers[i];
            int search = bSearch(numbers,i+1,numbers.size()-1,t);
            if (search!=-1) return {i+1,search+1};
        }
        return {};
    }
};
