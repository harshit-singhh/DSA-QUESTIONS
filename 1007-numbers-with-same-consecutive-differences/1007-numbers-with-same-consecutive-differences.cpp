class Solution {
    void solve(int n , int k  , int digit , vector<int>&ans ){
        if(n == 1){
            ans.push_back(digit);
            return;
        }

        int lastdigit = digit%10;
        if(lastdigit - k >= 0){
            int num = digit*10 + (lastdigit - k);
            solve(n-1 , k , num , ans);
        }
        if(k != 0){

            if(lastdigit + k <= 9){
                int num = digit*10 + (lastdigit+k);
                solve(n-1 , k , num , ans);
            }
            
        }
        
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;

        for(int i = 1 ; i<= 9 ; i++){
            solve(n , k , i , ans);
        }
        return ans;
    }
};