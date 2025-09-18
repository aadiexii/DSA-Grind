class Solution {
public:
    int functionSolve(int i, int j, vector<vector<int>>& matrix, int size, vector<vector<int>>& dp){
        if(j<0 || j>= size) return 1e9;
        if(i==0) return matrix[0][j];
        
        if(dp[i][j] != -1) return  dp[i][j];
        int up = matrix[i][j] + functionSolve(i-1, j, matrix, size, dp);
        int upleft = matrix[i][j] + functionSolve(i-1, j-1, matrix, size, dp);
        int upright = matrix[i][j] + functionSolve(i-1, j+1, matrix, size, dp);

        return dp[i][j] = min(up, min(upleft, upright));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int ans = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int i=0; i<n; i++){
        //     ans = min(ans, functionSolve(n-1, i, matrix, n, dp));
        // }

        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int upleft = 1e9;
                if(j-1>=0){ upleft = matrix[i][j] + dp[i-1][j-1];}
                int upright = 1e9;
                if(j+1 < n){ upright = matrix[i][j] + dp[i-1][j+1];}

                dp[i][j] = min(up, min(upleft, upright));
            }
        }

        int mini = dp[n-1][0];
        for(int j=1; j<n; j++){
            mini = min(mini, dp[n-1][j]);
        }

    return mini;
    }
};