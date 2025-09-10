class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;
        for(auto &friends: friendships){
            //Coverting into 1-based indexing as language is given in 0 based, 
            //So if friend[0] is 1 then 1-1 = 0, laguages[0] will be known to frined[0];
            int  friend1 = friends[0]-1;
            int  friend2 = friends[1]-1;

            unordered_set<int> lang(begin(languages[friend1]), end(languages[friend1]));
            bool cantheytalk = false;
            for(int lan: languages[friend2]){
                if(lang.count(lan)){
                    cantheytalk = true;
                    break; 
                }
            }

            if(!cantheytalk){
                sadUsers.insert(friend1);
                sadUsers.insert(friend2);
            }
        }

        //Find max known lang
        vector<int> language(n+1, 0);
        int mostkknown = 0;
        for(int user: sadUsers){
            for(int lang: languages[user]){
                language[lang]++;
                mostkknown = max(mostkknown, language[lang]);
            }
        }
        return sadUsers.size() - mostkknown;
    }
};