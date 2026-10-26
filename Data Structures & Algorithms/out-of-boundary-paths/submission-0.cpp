class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m,vector<int>(n));dp[startRow][startColumn]=1;int answer=0,dr[]={1,-1,0,0},dc[]={0,0,1,-1};for(int move=0;move<maxMove;move++){vector<vector<int>> next(m,vector<int>(n));for(int r=0;r<m;r++)for(int c=0;c<n;c++)for(int d=0;d<4;d++){int rr=r+dr[d],cc=c+dc[d];if(rr>=0&&rr<m&&cc>=0&&cc<n)next[rr][cc]=(next[rr][cc]+dp[r][c])%1000000007;else answer=(answer+dp[r][c])%1000000007;}dp=next;}return answer;
    }
};
