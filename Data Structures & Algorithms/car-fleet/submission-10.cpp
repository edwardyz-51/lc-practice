class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>fleet;
        double slowestTime = 0.0;
        int fleets = position.size();
        for (int i = 0; i<position.size(); i++){
             fleet.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }
        sort(fleet.rbegin(),fleet.rend());
        for (int i = 0; i<position.size(); i++){
            if (slowestTime==0.0){
                slowestTime = fleet[i].second;
            } 
            else if (slowestTime >= fleet[i].second){
                fleets--;
            } else {
                slowestTime = fleet[i].second;
            }

        }
        return fleets;
    }
};
