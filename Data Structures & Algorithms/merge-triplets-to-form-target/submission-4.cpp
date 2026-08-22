class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool idx1, idx2,idx3 = false;
        for (const auto& t : triplets){
            if (idx1 && idx2 && idx3) return true;
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue; //WOULD GET STUCK HERE
        
            for (int i = 0; i<3; ++i) { //i = the index
                if (t[i]==target[i]){
                    if (i==0) idx1=true;
                    else if (i==1) idx2=true;
                    else idx3=true;
            }
        }
        }
        return idx1 && idx2 && idx3;
    }
};
