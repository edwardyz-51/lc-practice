class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>scores;
        int score = 0;
        for (string& s : operations){
            if (s[0]=='+'){
                scores.push_back(scores.back() + scores[scores.size()-2]);
            }else if (s[0]=='D'){
                scores.push_back(scores.back()*2);
            } else if (s[0]=='C'){
                scores.pop_back();
            } else scores.push_back(stoi(s));
        }
        return accumulate(scores.begin(),scores.end(),score);
    }
};