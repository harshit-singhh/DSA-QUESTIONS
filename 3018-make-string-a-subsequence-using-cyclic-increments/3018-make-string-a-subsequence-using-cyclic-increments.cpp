class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();
        
        vector<int>first;
        
        for(int i = 0 ; i < n ; i++){
  
            first.push_back(str1[i] - 'a');
            
        }
        
        vector<int>second;
        
        for(int i = 0 ; i < m ; i++){
            second.push_back(str2[i] - 'a');
        }
        
        int index = 0;
        for(int i = 0 ; i < n ; i++){
            int original = second[index];
            int oneless = second[index] - 1;
            if(oneless == -1){
                oneless = 25;
            }
            
            if(first[i] == original || first[i] == oneless){
                index++;
            }
            
            if(index == m) return true;
        }
        return false;
        
        

    }
};