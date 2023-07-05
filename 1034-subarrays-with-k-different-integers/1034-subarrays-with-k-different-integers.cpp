class Solution {
public:

    int Atmost(vector<int> &arr, int n, int k){ // insane technique but fails at last couple of testcases.
        
        int left = 0 , right = 0, totalSubarrays = 0;
        
        if(k > n) return -1;
        
        unordered_map<int,int>mp;
        
        while(right < n){
            mp[arr[right]]++;
            
            while(mp.size() > k){
                mp[arr[left]]--;
                if(mp[arr[left]] == 0) mp.erase(arr[left]);
                left++;
            }
            
            int NoOfsubArray = right - left +1;
            totalSubarrays+= NoOfsubArray;
            right ++;
            
        }
        
        return totalSubarrays;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int m = arr.size();
         return Atmost(arr,m,k) - Atmost(arr,m,k-1);
    }
};