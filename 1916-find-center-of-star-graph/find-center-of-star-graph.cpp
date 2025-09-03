class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> mpp;
        for(auto it: edges){
            int a = it[0];
            int b = it[1];

            mpp[a]++;
            mpp[b]++;
        }

        for(auto &it: mpp){
            if(it.second== n){
                return it.first;
            }
        }
    return -1;
    }
};