class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr;
        int index = n/2;
        for(int i= -index; i<=index; i++){
            if(n%2 == 0 && i==0)continue;
            arr.push_back(i);
        }
    return arr;
    }
};