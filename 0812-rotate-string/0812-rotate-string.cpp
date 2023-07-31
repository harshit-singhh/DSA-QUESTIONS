class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()) return false;
        int n = s.size();

        if(s == goal) return true; 
        

        for(int i = 1 ; i < n ; i++){
            
            string ans = s.substr(i , n-i);
            string sub = s.substr(0 ,i);

            ans = ans+sub;

            if(ans == goal) return true; 
            
        }

        return false;
    }
};