//TOO SLOW: USE BFS
using adjT = unordered_map<string,unordered_set<string>>;
class Solution {
public:
    int pathfind(string cur, string& endWord, unordered_set<string>&visited, adjT& adj, int length){
        int res = INT_MAX;
        if (cur == endWord) return length+1;
        visited.insert(cur);
        for (auto &s : adj[cur]){
            if (visited.count(s)) continue;
            int temp = pathfind(s,endWord,visited,adj,length+1);
            res = min(temp,res);
        }
        visited.erase(cur);
        return res;
    }
    bool checkadj(string&a,string&b){
        bool ok = false;
        for (int idx = 0; idx < a.size(); ++idx){
                if (a[idx] != b[idx]){
                    if (ok) return false;
                    ok = true;
                }
        }
        return ok;
        
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        adjT adj;
        for (string&a : wordList){
            if (checkadj(beginWord,a)){
                adj[beginWord].insert(a);
                adj[a].insert(beginWord);
            }
            for (string &b : wordList){
                if (adj[a].count(b) || a==b) continue;
                if (checkadj(a,b)){
                    adj[a].insert(b);
                    adj[b].insert(a);
                }        
            }   
        }
        unordered_set<string>visited;
        int ans = min(pathfind(beginWord,endWord,visited, adj, 0),INT_MAX);

        return ans != INT_MAX ? ans : 0;
    }

    
};
