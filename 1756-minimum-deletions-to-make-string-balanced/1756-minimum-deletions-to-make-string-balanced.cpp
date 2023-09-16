class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int>a_count(n);
        vector<int>b_count(n);
        
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            b_count[i] = count;
            if(s[i] == 'b'){
                count++;
            }
        }
        count = 0;

        for(int i = n-1 ; i>= 0 ; i--){
            a_count[i] = count;
            if(s[i] == 'a') count++;
        }

        int ans = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            ans = min(ans , a_count[i] + b_count[i]);
        }

        return ans;
    }
};