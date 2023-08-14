class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        
        // code here
        int mx=0,mx_cnt=0;
        unordered_map<char,int>m;
        for(auto c : t){
            m[c]++;
            mx=max(mx,m[c]);
        }
        int count = 0;
        
        for(auto c : m){
            if(c.second == mx) count++;
        }
        
        int ans = (mx-1)*(n+1) + count;
        int k = t.size();
        return max(ans , k);
    }
};