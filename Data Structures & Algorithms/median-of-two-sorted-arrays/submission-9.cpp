class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size()+nums2.size();
        int med = size/2;
        int prev = 0, cur = 0;
        vector<int>::iterator p1 = nums1.begin();
        vector<int>::iterator p2 = nums2.begin();
        for (int i = 0; i < med+1; ++i){
        prev = cur;
        if (p1 == nums1.end()) {
            cur = *p2;
            ++p2;
        }
        else if (p2 == nums2.end()) {
            cur = *p1;
            ++p1;
        }
        else if (*p1 <= *p2) {
            cur = *p1;
            ++p1;
        }
        else {
            cur = *p2;
            ++p2;
        }
        }
        if (size % 2 == 1) return cur;
        return (double)(prev + cur) / 2;
        }
        
};
