class Solution {
public:
    string convertToTitle(int N) {
        string ans = "";
        
        // cout<<1 - 'A'<<endl;
        while(N > 0){
            int num = N%26;
            
            if(num == 0){
                ans.push_back('Z');
            }
            else ans.push_back((num - 1) + 'A');
            
            N/= 26;
            
            if(num == 0) N = N-1;
            
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};