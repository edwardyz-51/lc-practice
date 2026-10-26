class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), ans = n;
        vector<int> cars (n);
        iota(cars.begin(),cars.end(),0);
        ranges::sort(cars,[&position](int a, int b){
            return position[a] > position[b];
        });
        //time = (target-position[i]) / speed[i]
        double slowest = (double)(target-position[cars[0]]) / speed[cars[0]];
        for (size_t i(1uz); i < n; ++i){
            double time = (double)(target-position[cars[i]]) / speed[cars[i]];
            time <= slowest ? ans-- : slowest = time;
        }
        return ans;
    }
};
