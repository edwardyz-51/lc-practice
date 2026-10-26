class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string temp;
        stack<string>st, rev;
        while (getline(ss,temp,'/')) if (!temp.empty()) st.push(temp);
        int skips = 0;
        while (!st.empty()){
            if (st.top()=="."){
                st.pop();
                continue;
            } 
            if (st.top()=="..")
                skips++;
            else if (skips>0)
                skips--;
            else 
                rev.push(st.top());
            st.pop();
        }
        string ans;
        while (!rev.empty()){
            ans += "/" + rev.top();
            rev.pop();
        }
        return ans.empty() ? "/" : ans;


        
    }
};