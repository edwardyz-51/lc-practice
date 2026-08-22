class KthLargest {
public:
    vector<int>arr;
    int kay;
    KthLargest(int k, vector<int>& nums) {
        arr=nums;
        kay=k;
    }
    
    int add(int val) {
        arr.push_back(val);

        sort(arr.begin(),arr.end());
        return arr[arr.size()-kay];
    }
};
