class Solution {
public:

    bool ispossible(vector<int>&piles ,int n , int k , int hour){

        int time = 0;
        bool not_possible = false;
        for(int i = 0 ; i < n ; i ++){
            if(piles[i] % k != 0 ){
                time += piles[i]/k;
                time++;
            }
            else{
                time += piles[i]/k;
            }

            if(time > hour){
                not_possible = true;
                break;
            }
        }
        return !not_possible;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin() , piles.end());
        int n = piles.size();
        int min_k = INT_MAX;
        while(low <= high){
            
            int k = low + (high - low) /2;
            if(ispossible(piles, n , k , h)){
                min_k = min(min_k , k);
                high = k - 1;
            }
            else{
                low = k+1;
            }
        }

        return min_k;
    }
};