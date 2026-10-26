class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), ans = n;
        vector<int> cars (n);
        iota(cars.begin(),cars.end(),0);
        ranges::sort(cars,[&position](int a, int b){
            return position[a] > position[b];
        });
        double slowest = -1;
        for (size_t i(0uz); i < n; ++i){
            double time = (double)(target-position[cars[i]]) / speed[cars[i]];
            time <= slowest ? ans-- : slowest = time;
        }
        return ans;
    }
};
