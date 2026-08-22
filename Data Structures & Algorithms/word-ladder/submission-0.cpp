using adjT = unordered_map<string,unordered_set<string>>;
class Solution {
public:
    int pathfind(string cur, string& endWord, unordered_set<string>&visited, adjT& adj, int length){
        int res = INT_MAX;
        if (cur == endWord) return length;
        visited.insert(cur);
        for (auto &s : adj[cur]){
            if (visited.count(s)) continue;
            int temp = pathfind(s,endWord,visited,adj,length+1);
            res = res < temp ? res : temp;
        }
        return res;
    }
    void checkadj(string&a,string&b,adjT&adj){
        bool ok = true;
        for (int idx = 0; idx < a.size(); ++idx){
                if (a[idx] != b[idx]){
                    if (!ok) return;
                    ok = false;
                }
        }
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        adjT adj;
        for (string&a : wordList){
            checkadj(beginWord,a,adj);
            for (string &b : wordList){
                if (adj[a].count(b) || a==b) continue;
                checkadj(a,b,adj);        
            }   
        }
        unordered_set<string>visited;
        int ans = min(pathfind(beginWord,endWord,visited, adj, 1),INT_MAX);

        return ans != INT_MAX ? ans : 0;
    }

    
};
