class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /* int bph = 1;
        int hours = 0;
        for (int i = 0; i<piles.size(); i++) {
            hours += (piles[i]+bph-1)/bph;
            if (hours > h){
                i = -1;
                hours = 0;
                bph++;
            }
        }
        return bph;
        */
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while (low<=high) {
            int middle = (low+high) /2;
            int hours = 0;
            for (int p : piles) {
                hours += (p + middle - 1) / middle;
            }
            if (hours <=h) {
                ans = middle;
                high = middle-1;
            } else {
                low = middle+1;
            }
        }
        return ans;
    }
};
