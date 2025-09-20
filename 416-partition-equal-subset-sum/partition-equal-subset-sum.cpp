class Solution {
public:
    bool allSubsets(int index,int sum, vector<int>& arr, int n, vector<vector<int>> &dp){
        if(sum == 0){
            return true;
        }
        if(index == 0){
            return (arr[index] == sum);
        }
        if(dp[index][sum] != -1) return dp[index][sum];
        bool notPick = allSubsets(index-1, sum, arr,n, dp);
        bool pick = false;
        if(sum >= arr[index]){
             pick = allSubsets(index-1, sum-arr[index], arr,n, dp);
        }
        
        return dp[index][sum] =  notPick || pick;
    }
    bool canPartition(vector<int>& nums) {
         // code here
             int n = nums.size();
             int totalSum = 0;
             for(int i=0; i<n; i++){
                totalSum += nums[i];
             }
             if(totalSum % 2 != 0) return false;
             int target = totalSum / 2;
             vector<vector<int>> dp(n, vector<int>(target+1, -1));
             bool ans = allSubsets(n-1,target, nums,n, dp);
             return ans;       
    }
};