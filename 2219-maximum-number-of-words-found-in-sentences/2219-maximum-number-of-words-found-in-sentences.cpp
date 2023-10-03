class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
            int maxi = INT_MIN;

            for(auto it: sentences){

                int count = 0;
                for(auto k : it){
                    
                    if(k == ' ') count++;

                }

                maxi = max(maxi , count+1);
            }

            return maxi;
    }
};