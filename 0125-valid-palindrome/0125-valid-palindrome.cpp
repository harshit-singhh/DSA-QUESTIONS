class Solution {
public:
    bool isPalindrome(string s) {
        string str="",chk="",tmp="";
        for(char c: s){
            str+= tolower(c);
        }
        int n=str.size();
        for(int i=0;i<n;i++ )
{
    if((str[i]>=97 && str[i]<=122)|| (str[i]>=48 && str[i]<=57)) chk+=str[i];
}   tmp=chk;
reverse(chk.begin(),chk.end());
if (chk==tmp) return 1;     

        return 0;
        
    }
};