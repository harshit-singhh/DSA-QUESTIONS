class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = 0;

        string ans = "";
        bool first = true;
        while(left < s.size()){
            right = left+1;

            while(s[right] != ' ' && right != s.size()){
                right++;
            }

            string sub = s.substr(left , right - left);
            reverse(sub.begin() , sub.end());

            left= right+1;

            if(first){
                ans+= sub;
                first = false;
            }
            else{
                ans += " " + sub;
            }
        }
        return ans;
    }
};