class Solution {
    bool possible(string& s , int left , int right , unordered_map<string , int>&mp , int wordsize , 
    int totalwords){

        unordered_map<string ,int> mp2;
        int count = 0;
        string str = "";
        for(int i = left ; i <= right ; i++){
            count++;
            str.push_back(s[i]);
            if(count == wordsize){
                mp2[str]++;
                str = "";
                count = 0;
            }


        }

        int wordsCount = 0;
        for(auto it: mp2){
             if(mp[it.first] != it.second){
                 return false;
             }
             wordsCount++;
        }

        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int totalwords = words.size();
        int wordsize = words[0].size();
        int totalsize = totalwords*wordsize;
        int left = 0;
        int right = totalsize-1;

        int n = s.size();

        vector<int>ans;
        unordered_map<string , int>mp1;
        for(int i = 0 ; i < totalwords ; i++){
            mp1[words[i]]++;
        }


        while(right <  n){

            if(possible(s , left , right , mp1 , wordsize , totalwords)){
                ans.push_back(left);
            }

            right++;
            left++;
        }

        return ans;
    }
};