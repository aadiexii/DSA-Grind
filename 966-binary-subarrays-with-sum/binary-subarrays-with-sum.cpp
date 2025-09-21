class Solution {
public:
    int function(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int count = 0;
        for(int r=0; r<n; r++){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }
    
            count += (r-l+1);
        }
    return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return function(nums, goal) - function(nums, goal-1);
    }
};