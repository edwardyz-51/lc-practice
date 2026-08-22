class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>cars;
        //pair<position, time to reach target>
        for (int i = 0; i < position.size(); ++i){
            cars.push_back({position[i], (double)(target-position[i])/speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        //sort by position, descending
        int ans = cars.size();
        double slowestsofar = cars[0].second;
        for (int i = 1; i < cars.size(); ++i){
            if (cars[i].second <= slowestsofar){
                ans--;
            } else slowestsofar=cars[i].second;
        }
        return ans;
    }
};
