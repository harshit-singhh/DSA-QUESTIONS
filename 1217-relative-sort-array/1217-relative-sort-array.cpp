class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        int N = arr1.size();
        int M = arr2.size();
         sort(arr1.begin() , arr1.end());
        
        unordered_map<int,int>mp;
        
        for(int i = 0 ; i < M ; i++) mp[arr2[i]] = 0;
        for(int i = 0 ; i < N ; i++ ){
            if(mp.find(arr1[i]) != mp.end()){
                mp[arr1[i]]++;
            }
        }
        
        vector<int>ans;
        for(int i = 0 ; i < M ; i++){
            int count = mp[arr2[i]];
            
            while(count--){
                ans.push_back(arr2[i]);
            }
        }
        
        for(int i = 0 ; i < N ; i++){
            if(mp.find(arr1[i]) == mp.end()){
                ans.push_back(arr1[i]);
            }
        }
        
        return ans;
    }
};