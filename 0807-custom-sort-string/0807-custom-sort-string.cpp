class Solution {
public:
    string customSortString(string order, string s) {
        map<char , int>mp;

        for(auto it: s){
            mp[it]++;
        }
        string ans = "";
        for(auto it: order){
            while(mp[it] >= 1){
                ans.push_back(it);
                mp[it]--;
            }
        }

        for(auto it: mp){
            while(it.second > 0){
                ans.push_back(it.first);
                it.second--;
            }
        }

        return ans;
    }
};