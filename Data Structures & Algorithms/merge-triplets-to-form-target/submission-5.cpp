class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool>idx(3,false);
        for (const auto& t : triplets){
            if (idx[0] && idx[1] && idx[2]) return true;
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue; //WOULD GET STUCK HERE
        
            for (int i = 0; i<3; ++i) { //i = the index
                if (t[i]==target[i]){
                    idx[i]=true;
            }
        }
        }
        return idx[0] && idx[1] && idx[2];
    }
};
