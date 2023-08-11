class Solution {
public:
    // string minWindow(string s, string p) {
    //     int count=0;
    //     vector<int>mp(26,0);
    //     for(int i=0;i<p.size();i++){
    //       if(mp[p[i]-'a']==0){
            
    //           count++;
    //       }
    //         mp[p[i]-'a']++;
    //     }
        
    //     int i=0,j=0;
    //     int mini=INT_MAX,start=0,end=0;
    //     while(j<s.size()){
    //         mp[s[j]-'a']--;
    //         if(mp[s[j]-'a']==0) count--;
    //         while(count==0){
    //             if(j-i+1<mini){
    //                   mini=min(j-i+1,mini);
    //                 start=i;
    //                 end=j;
    //             }
              

    //             mp[s[i]-'a']++;
    //             if(mp[s[i]-'a']==1) count++;
               
    //             i++;
    //         }
    //         j++;
    //     }
    //     if(mini!=INT_MAX){
    //         return s.substr(start,mini);
    //     }
    //     else {
    //         return "-1";
    //     }
    // }


     string minWindow(string s, string p){
         unordered_map<char , int>m;
         int count =0;
         for(auto it : p){
             if(m[it] == 0) count++;
             m[it]++;
         }
         
         int left = 0;
         int right = 0;
         int leftIndex = 0;
         int rightIndex = 0;
         int len = INT_MAX;
         int n = s.size();
          
         
         while(right < n){
             m[s[right]]--;
             if(m[s[right]] == 0) count--;
             
             while(count == 0){
                 if((right - left + 1) < len){
                     len = right - left + 1;
                     leftIndex = left;
                     rightIndex = right;
                 }
                 
                 m[s[left]]++;
                 if(m[s[left]] == 1) count++;
                 left++;
             }
             right++;
         }
         
         if(len == INT_MAX) return "";
         
         string sub = s.substr(leftIndex , len);
         return sub;
     }
};