class Solution {
    int dp[1005];
    int solve(vector<int>&cost , int index){
        if(index >= cost.size()){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int steps = 0;

        steps = cost[index] + min(solve(cost , index+1) , solve(cost , index+2));

        return dp[index] = steps;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        memset(dp , -1 ,sizeof(dp));
        int steps1 = solve(cost , 0);
        int steps2 = solve(cost , 1);
        return min(steps1 , steps2);
    }
};