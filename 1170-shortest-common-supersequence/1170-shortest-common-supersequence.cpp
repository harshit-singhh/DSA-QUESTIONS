class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else {

                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        int i = n;
        int j = m;
        string s = "";
        while(i> 0 && j > 0){
            if(s1[i-1] == s2[j - 1]){
                s.push_back(s1[i-1]);
                i--;
                j--;
            }
            else if(dp[i][j-1] < dp[i-1][j]){
                s.push_back(s1[i-1]);
                i--;
            }
            
            else{
                s.push_back(s2[j-1]);
                j--;
            }
        }
        
        while(i > 0){
            s.push_back(s1[i-1]);
            i--;
        }
        while(j > 0){
            s.push_back(s2[j-1]);
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};