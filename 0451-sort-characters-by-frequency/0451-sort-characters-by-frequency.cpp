
bool comp(pair<char,int>&a , pair<char,int>&b){
    return a.second > b.second;
}

class Solution {
public:
    string frequencySort(string s) {
        map<char, int>m;

        for(int i = 0 ; i < s.size(); i++){
            m[s[i]]++;
        }

        vector<pair<char,int>>temp(m.begin(),m.end());

        sort(temp.begin(),temp.end(),comp);

        map<char,int>sortedMap;



        string ans = "";

        for(auto it : temp){
            while(it.second--){
                ans.push_back(it.first);
            }
        }

        return ans;



    }
};