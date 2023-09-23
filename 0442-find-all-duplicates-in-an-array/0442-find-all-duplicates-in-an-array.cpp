class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        for(auto it:mp){
            if(it.second>1){
                v.push_back(it.first);
            }
        }
        
        sort(v.begin(),v.end());
        return v;
    }
};