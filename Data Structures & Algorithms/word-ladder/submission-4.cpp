class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(string &w: wordList){
            st.insert(w);
        }
        int ct=0;
        queue<pair<string,int>> q;
        q.push({beginWord,0});

        while(!q.empty()){
            auto [s,k]=q.front();
            q.pop();
        
            if(s==endWord) return k+1;
            
            for(int i=0;i<s.size();i++){
                 string temp=s;
                 for(int j=0;j<26;j++){
                    temp[i]=char('a'+j);
                    if(st.find(temp)!=st.end()){
                        q.push({temp,k+1});
                        st.erase(temp);
                    }
                 }
            }
        }

        return 0;
    }
};