class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int fleets = position.size();
        vector<pair<int,double>>pairs;
//position, time
        for (int i = 0; i < position.size(); i++) {
            pairs.push_back({ position[i], (double)(target - position[i]) / speed[i] });
        }
        sort(pairs.rbegin(),pairs.rend());
        stack<pair<int,double>>stack;
        for (int i = 0; i < position.size(); i++) {
            if (stack.empty()) {
                stack.push(pairs[i]);               
            } else if (pairs[i].second <= stack.top().second){ //if (car passes [time is less than stack.top]) 
                fleets--;
            } else {
                stack.push(pairs[i]);
            }
            

        }
        return fleets;
    }
};
