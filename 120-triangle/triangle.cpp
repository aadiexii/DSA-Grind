class Solution {
public:
    int functionSolve(int i,int j,vector<vector<int>>& triangle, int n,vector<vector<int>>& dp){
        if(i==n-1)return triangle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + functionSolve(i+1,j,triangle,n,dp);
        int downDiag = triangle[i][j] + functionSolve(i+1,j+1,triangle,n,dp);

        return dp[i][j] =  min(down, downDiag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
            int down = triangle[i][j] + dp[i+1][j];
            int downDiag = triangle[i][j] + dp[i+1][j+1];
        
            dp[i][j] = min(down, downDiag);
            }
        }
        return dp[0][0];
    }
};