class Solution {
public:
    string sortVowels(string s) {
        vector<pair<char, int>> vec;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                vec.push_back({s[i], (int)s[i]});
            }
        }

        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.first < b.second;
        });
        
        int k=0;
        string ans = "";
        for(int i=0; i<n; i++){         
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i] =='I'||s[i]=='O'||s[i]=='U'){
                s[i] = vec[k].first;
                ans += s[i];
                k++; 
            }
            else{
                ans += s[i];
            }
        }
    return ans;
    }
};