class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n = bills.size();

        int fivecount = 0;
        int tencount = 0;

        for(int i = 0 ; i < n ; i ++){
            int bill = bills[i];
            if(bill== 5) fivecount++;
            else if(bill == 10  ){
                tencount++;
                if(fivecount == 0 ) return false; 
                else fivecount--;
            }
            else if(bill == 20){
                if(fivecount> 0 && tencount > 0 ){
                    fivecount--;
                    tencount--;
                    continue;
                }
                if(fivecount >= 3){
                    fivecount-=3;
                    continue;
                }
                
                return false;
            }
        }
        return true;
    }
};