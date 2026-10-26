class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ranges::sort(people);
        int l = 0, r = people.size()-1;
        int boats = 0;
        while (l <= r) {
            if (people[l]+people[r] <= limit) {
                l++;
            }
            r--;
            boats++;
        }
        return boats;
    }
};