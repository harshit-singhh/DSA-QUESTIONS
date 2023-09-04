class Solution {
public:
    int nextGreaterElement(int N) {
        // if(N > 2e9) return -1;
        int breakindex = -1;
        int breakelement = -1;
        
        string str = to_string(N);
        
        int n = str.size();
        
        for(int i = n-2 ; i >= 0 ; i--){
            if(str[i] - '0' < str[i+1] - '0'){
                breakindex = i;
                breakelement = str[i] - '0';
                break;
            }
        }
        
        if(breakindex == -1) return -1;
        
        for(int i = n -1 ; i >= 0  ;i--){
            if(str[i] - '0' > breakelement){
                swap(str[breakindex] , str[i]);
                break;
            }
        }
        
        
        reverse(str.begin() + breakindex+1 , str.end());
        
        long long ans = stoll(str);

        if(ans < 0 || ans > INT_MAX) return -1;
        
        else ans = (int)ans;
        return ans;
    }
};