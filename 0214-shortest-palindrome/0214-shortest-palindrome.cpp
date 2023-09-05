class Solution {
public:
    string shortestPalindrome(string s) {
        int originallen = s.size();
        reverse(s.begin() , s.end());
        string revstring = s;
        reverse(s.begin() , s.end());
        string str = s + "&" + revstring;

        int n = str.size();

        vector<int>lps(n);
        lps[0] = 0;

        int left = 0;
        int right = 1;

        while(right < n){
            if(str[left] == str[right]){
                lps[right] = left+1;
                left++;
                right++;
            }
            else{
                if(left == 0){
                    lps[right ] = 0;
                    right++;
                }
                else{
                    left = lps[left-1];
                }
            }
        }

        int to_add = originallen - lps[n-1];

        string temp = "";
        int index = originallen - 1;
        for(int i = 0 ; i < to_add ; i++){
            temp.push_back(s[index]);
            index--;
        }

        temp += s;
        return temp;
    }
};