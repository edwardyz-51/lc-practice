class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int b : bills) {
            if (b == 5) five++;
            else if (b == 10) five--, ten++;
            else ten ? five--, ten-- : five-=3;
            if (five < 0) return false;
        }
        return true;
    }
};