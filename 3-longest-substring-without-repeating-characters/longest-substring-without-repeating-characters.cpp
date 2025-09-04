class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Brute Aproach -> Generating all the substring
        if(s.size() == 0) return 0;
        int maxLen = INT_MIN;
        for(int i=0; i<s.size(); i++){
            vector<int> hash(256, 0);
            int len = 0;
            for(int j=i; j<s.size(); j++){
                if(hash[s[j]] == 1) break;
                len = j-i+1;
                maxLen = max(maxLen, len);
                hash[s[j]] = 1;
            }
        }
    return maxLen;
    }
};