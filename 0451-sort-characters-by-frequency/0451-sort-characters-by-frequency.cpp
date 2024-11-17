
bool comp(const pair<char,int>a , const pair<char ,int>b){
        return a.second > b.second;
}

class Solution {
public:

    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int>mp;
        for(int i = 0 ; i < n ; i ++){
            mp[s[i]]++;
        }

        vector<pair<char , int>>temp(mp.begin() , mp.end());

        sort(temp.begin() , temp.end() , comp);

        string ans = "";

        for(auto it : temp){
            while(it.second--){
                
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};