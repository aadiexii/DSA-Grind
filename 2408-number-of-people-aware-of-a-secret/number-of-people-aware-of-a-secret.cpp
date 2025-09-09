class Solution {
public:
    int M = 1e9 + 7;

    //This will retur the total no of people who will know the secret on the day "day".
    int solve(int day, int delay, int forget, vector<int> &memo){
        if(day == 1) return 1;
        
        if(memo[day] != -1){
            return memo[day];
        }
        int result = 0;
        for(int i=day-forget+1; i<=day-delay; i++){
            if(i > 0){
                result = (result + solve(i, delay, forget, memo))%M;
            }
        }
    return memo[day]=result;   
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;
        vector<int> memo(n+1, -1);
        for(int i=n-forget+1; i<=n; i++){
            if(i > 0){
                total = (total + solve(i, delay, forget, memo))%M;
            }
        }
    return total;
    }
};