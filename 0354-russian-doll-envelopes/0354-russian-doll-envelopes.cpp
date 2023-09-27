
bool comp(vector<int>a , vector<int>b){
      if(a[0] == b[0]){
        return a[1] > b[1];
      }
      else return a[0] < b[0];
}


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int>arr;
        for(int i =0;i<n;i++)
        {
            if(arr.empty() || arr.back()<envelopes[i][1])
                arr.push_back(envelopes[i][1]);
            else
            {
                int index = lower_bound(arr.begin(),arr.end(),envelopes[i][1])
                        -   arr.begin();
                arr[index] = envelopes[i][1];
            }
        }
        
        return arr.size();
    
    }
};









// class Solution {
    
//     int solve(vector<vector<int>>&arr , int n , int index , int prev ,vector<vector<int>>&dp){
//         if(index == n ) return 0;

//         if(dp[index][prev+1] != -1) return dp[index][prev+1];

//         int pick = 0;
//         if(prev == -1 || (arr[index][0] > arr[prev][0] && arr[index][1] > arr[prev][1] ) ){
//             pick = 1 + solve(arr, n , index+1 , index ,dp);
//         }

//         int notpick = 0 + solve(arr , n , index+1 , prev ,dp );

//         return dp[index][prev+1] = max(pick , notpick);
//     }
// public:
//     int maxEnvelopes(vector<vector<int>>& env) {
        
//         sort(env.begin() , env.end() , comp);

//         int n = env.size();

//         vector<vector<int>>dp(n+1 , vector<int>(n+1, -1));

//         // memset(dp , -1 , sizeof(dp));

//         return solve(env , n , 0 , -1 ,dp);
//     }
// };