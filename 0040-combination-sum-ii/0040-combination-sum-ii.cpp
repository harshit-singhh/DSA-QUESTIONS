class Solution {
public:

    
    void help(vector<vector<int>>&ans,vector<int> &candidates, int target,vector<int>ds,int ind){
        
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
        for(int i = ind ; i < candidates.size(); i++){
            if(i > ind && candidates[i]==candidates[i-1]){
                continue;
            }
            
            if(candidates[i]>target){
                break;
            }
            
            ds.push_back(candidates[i]);
            help(ans,candidates,target-candidates[i],ds,i+1);
            ds.pop_back();
        }
        
    
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        
        sort(candidates.begin(),candidates.end());
        help(ans,candidates,target,ds,0);
        
        return ans;
        
    } 
};