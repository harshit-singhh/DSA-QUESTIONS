class Solution {
    int findlen(string str){
        
        int len = 0;

        for(auto it: str){
            len++;
        }

        return len;
    }

    bool hamming(string s1 , string s2 , int n ){
        int diff = 0;

        for(int i = 0 ; i < n;  i++){
            if(s1[i] != s2[i]){
                diff++;
            }
        }

        return diff == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        
        vector<int>prev(n , -1);
        vector<int>dp(n , 1);
        vector<int>len(n , 0);
        for(int i = 0 ; i< n ; i++){
            int length = findlen(words[i]);
            len[i] = length;
        }

        for(int i = 0 ; i < n ; i++) prev[i] = i;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(groups[i] != groups[j]){
                    if(len[i] == len[j]){
                        if(hamming(words[i] , words[j] , len[i])){
                            if(dp[j] + 1 > dp[i]){
                                dp[i] = dp[j] + 1;
                                prev[i] = j;
                            }
                        }
                    }
                }
            }
        }

        int index = -1;
        int maxi = -1;

        for(int i = 0 ; i < n ; i++){
            if(dp[i] > maxi){
                maxi = dp[i];
                index = i;
            }
        }


        vector<string>ans;

        while(index != prev[index]){
            ans.push_back(words[index]);
            index = prev[index];
        }

        ans.push_back(words[index]);
        reverse(ans.begin() , ans.end());

        return ans;


    }
};