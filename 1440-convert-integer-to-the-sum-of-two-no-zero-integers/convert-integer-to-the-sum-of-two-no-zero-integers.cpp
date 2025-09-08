class Solution {
public:
    bool check(int num){
        while(num > 0){
            int digit = num % 10;
            if(digit == 0) return false;
            num = num/10;
        }
    return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int a=1; a<n; a++){
            int b = n - a;
            if(check(a) && check(b)){
                return {a, b};
            }
        }   
    return {-1, -1};
    }
};