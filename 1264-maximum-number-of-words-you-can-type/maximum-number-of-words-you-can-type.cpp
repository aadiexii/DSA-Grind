class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        unordered_set<char> st;
        for(auto &c: brokenLetters){
            st.insert(c);
        }

        int ans = true;
        for(char &ch: text){
            if(ch == ' '){
                if(ans){
                    count++;
                }
                ans = true;
            }else if(st.count(ch)){
                ans = false;
            }
        }

        if(ans){
            count++;
        }
    return count;
    }
};