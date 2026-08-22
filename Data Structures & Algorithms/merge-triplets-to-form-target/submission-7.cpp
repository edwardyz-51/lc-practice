class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool>idx(3,false);
        for (auto& v : triplets){
            if (v[0]>target[0] || v[1]>target[1] || v[2]>target[2]) continue;
            for (int i = 0; i < 3; ++i) if (v[i]==target[i])idx[i]=true;
        }
        return idx[0]&&idx[1]&&idx[2];
    }
};
