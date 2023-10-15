class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
    //     int mini = INT_MAX;
    //     int n = s.size();
    //     int left = 0 , right = 0 , count = 0;
    //     int len = 0;
    //     bool first = true;
    //     string ans;
    //     while(right < n ){
    //         if(s[right] == '1'){
    //             count++;
    //         }

    //         while(count == k){
    //             len = right - left + 1;
    //             if(first){
    //                 string str = s.substr(left , right - left +1);
    //                 ans = str;
    //                 first = false;
    //             }
    //             else if(len < mini){
    //                 mini = len;
    //                 string str = s.substr(left , right - left + 1);
    //                 if(str < ans){
    //                     ans = str;
    //                 }
    //             }

    //             else if(len == mini){
    //                 string str = s.substr(left , right - left + 1);
    //                 if(str < ans){
    //                     ans = str;
    //                 }
    //             }

    //             if(s[left] == '1'){
    //                 count--;
    //             }
    //             left++;
                
    //         }

    //         right++;
    //     }

    //     return ans;
    // }

        int n = s.size();
        int left = 0, right = 0, count = 0;
        int len = 0;
        int mini = n + 1;  // Initialize mini to a value greater than any potential substring length
        bool first = true;
        string ans;
        
        while (right < n) {
            if (s[right] == '1') {
                count++;
            }

            while (count == k) {
                len = right - left + 1;
                if (first || len < mini) {
                    mini = len;
                    ans = s.substr(left, len);
                    first = false;
                } else if (len == mini) {
                    string str = s.substr(left, len);
                    if (str < ans) {
                        ans = str;
                    }
                }

                if (s[left] == '1') {
                    count--;
                }
                left++;
            }

            right++;
        }

        return first ? "" : ans;
    }
};