class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        ranges::sort(arr,[&](int a, int b) {
            int t1 = abs(a-x), t2 = abs(b-x);
            return t1==t2 ? a < b : t1<t2;
        });
        vector<int> temp(
            make_move_iterator(arr.begin()),
            make_move_iterator(arr.begin() + k)
        );
        ranges::sort(temp);
        return temp;
    }
};