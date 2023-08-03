class Solution {
public:
    int countHomogenous(string s) {
        int left = 0;
        int right = 1;

        long long int count = 0;
        int mod = 1e9+7;
        
        while(right < s.size()){
            if(s[right] != s[right -1]){
                long long len = right - left;
                
                count = (count + (len*(len+1))/2)%mod;
                left = right;
                right++;
            }
            else{
                right++;
            }
        }
        long long len = right - left;
        count = (count + (len *( len +1))/2)%mod;

        return count;
    }
};



// class Solution {
// public:
//     int countHomogenous(string s) {
//         long long int ans = 0;
//         int mod = pow(10, 9) + 7;
//         long long int count = 1;
//         for (int i = 1; i < s.length(); i++) {
//             if (s[i] == s[i-1]) {
//                 count += 1;
//             } else {
//                 ans = (ans + (count * (count + 1)) / 2) % mod;
//                 count = 1;
//             }
//         }
//         ans = (ans + (count * (count + 1)) / 2) % mod;
//         return (int) ans;
//     }
// };