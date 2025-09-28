class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> num1, num2;
        for(int i=0; i<nums.size(); i++){
           if(i % 2 != 0){
               num1.push_back(nums[i]);
           }
           else{
            num2.push_back(nums[i]);
           }
        }  

        vector<int> arr(n);
        int index1 = 0;
        int index2 = 0;
        for(int i=0; i<n; i++){
           if(i % 2 != 0){
               arr[i]=(num2[index1]);
               index1++;
           }
           else{
               arr[i]=(num1[index2]);
               index2++;
           }

        }
    return arr;
    }
};