class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>fleet;
        
        int fleets = position.size();
        for (int i = 0; i<position.size(); i++)
             fleet.push_back({position[i], (double)(target - position[i]) / speed[i]});
        //position, time to finish
        sort(fleet.rbegin(),fleet.rend());
        double slowestTime = fleet[0].second;
        for (int i = 1; i<position.size(); i++){
            if (slowestTime >= fleet[i].second) fleets--;
            else slowestTime = fleet[i].second;
        }
        return fleets;
    }
};
