class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto lambda = [&](int a, int b) {
            int t1 = abs(a-x), t2 = abs(b-x);
            return t1==t2 ? a < b : t1<t2;
        };
        ranges::sort(arr,lambda);
        vector<int> temp(arr.begin(),arr.begin()+k);
        ranges::sort(temp);
        return temp;
    }
};