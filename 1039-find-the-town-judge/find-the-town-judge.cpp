class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //  set<int> st1;
        //  set<int> st2;
        //  for(auto it: trust){
            
        //     st1.insert(it[0]);
        //     st2.insert(it[1]);
        //  }

        //  int ans;
        //  if(st1.size() == trust.size() && st2.size() == 1){
        //     ans = *st2.begin();
        //  }
        //  else {
        //     ans = -1;
        //  }
        //  return ans;
        vector<int> inDegree(n+1, 0);
        vector<int> outDegree(n+1, 0);

        for(auto &it: trust){
            outDegree[it[0]]++;
            inDegree[it[1]]++;
        }

        for(int i=1; i<=n; i++){
           if(inDegree[i] == n-1 && outDegree[i] == 0){
            return i;
           }
        }
    return -1;
    }
};