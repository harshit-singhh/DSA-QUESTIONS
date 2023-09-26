class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<bool>visited(26 , false );
        vector<int>LastIndex(26 , -1);

        for(int i = n-1 ; i >= 0 ; i--){

            if(LastIndex[s[i] - 'a'] == -1){
                LastIndex[s[i] - 'a'] = i;
            }
        }

        string ans = "";
        int size = ans.size();
        for(int i = 0 ; i < n ; i++){
            
            int currIndex = i;
            while(visited[s[currIndex] - 'a'] == false && size > 0 && s[i] < ans[size-1] && LastIndex[ans[size-1] - 'a'] > i ){
                visited[ans[size-1] - 'a'] = false;
                ans.pop_back();
                size--;
            }

            if(visited[s[i] - 'a'] == false){

                ans.push_back(s[i]);
                size++;
                visited[s[i] - 'a'] = true;
            }

        }

        return ans;
    }
};