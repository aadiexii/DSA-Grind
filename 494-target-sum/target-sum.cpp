class Solution {
  int solve(int index,int target,vector<int>& arr, vector<vector<int>> &dp){
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0) return 1;
            if (arr[0] == target) return 1;
            return 0;
        }

        if(dp[index][target] != -1) return dp[index][target];
        int notpick = solve(index-1, target, arr, dp);
        int pick = 0;
        if(arr[index] <= target) pick = solve(index -1, target-arr[index], arr, dp);
        
        return dp[index][target] = pick + notpick;
  }
  private:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(n-1, target, arr, dp);
    }
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totalSum = 0;
        for(int i=0; i<arr.size(); i++){
            totalSum += arr[i];
        }
        
        if(totalSum - d < 0 || (totalSum - d) % 2) return 0;
        return perfectSum(arr, (totalSum - d)/2);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};