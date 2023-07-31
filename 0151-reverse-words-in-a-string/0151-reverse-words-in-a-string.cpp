class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i =0;
        string ans;
        while(i < n){
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;
            int j = i+1;
            while(j < n && s[j] != ' ') j++;

            string sub = s.substr(i , j-i);

            if(ans.size() == 0) ans = sub;
            else ans = sub + " " + ans;
            

            i = j+1;


        }

        return ans;
        
    }
};