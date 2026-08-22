class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size()+nums2.size();
        int med = size/2;
        bool odd = size % 2 == 1;
        int prev = 0, cur = 0;
        std::vector<int>::iterator p1 = nums1.begin();
        std::vector<int>::iterator p2 = nums2.begin(); //if both come from the same
        for (int i = 0; i < med+1; ++i){
            prev = cur;
            if (p1 != nums1.end() && (p2 == nums2.end() || *p1 <= *p2)) {
                cur = *p1;
                ++p1;
            } else {
                cur = *p2;
                ++p2;
            }
        }
            if (odd) return cur;
            return (double)(prev + cur) / 2;
        }
        
};
