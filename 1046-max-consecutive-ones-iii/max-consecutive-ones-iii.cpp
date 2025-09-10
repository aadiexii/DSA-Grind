class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //1.Brute Approach -> Question boils dowm to generate ,\max subaarrau with atmost k 0s
    //     int maxlen = 0;
    //     for(int i=0; i<nums.size(); i++){
    //         int zeroes = 0;
    //         for(int j=i; j<nums.size(); j++){
    //             if(nums[j] == 0){
    //                 zeroes++;
    //             }
    //             if(zeroes <= k){
    //                 int len = j-i+1;
    //                 maxlen = max(len, maxlen);
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //     } 
    // return maxlen;

    //Using two Pointer -> Sliding Window
    int n = nums.size();
       int l = 0;
       int r = 0;
       int maxLen = 0;
       int zeroes = 0;
       while(r<n){
        if(nums[r] == 0){
           zeroes++;
        }
        while(zeroes > k){
            if(nums[l] == 0){
                zeroes--;
            }
            l++;
        }
        if(zeroes<=k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;
       }
    return maxLen;
    }
};