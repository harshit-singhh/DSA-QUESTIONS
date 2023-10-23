class Solution {
public:
    bool isPowerOfFour(int n) {
        
        int onecount = 0;

        for(int i = 0 ; i < 32 ; i++){
            if((n & (1 << i)) != 0 ) onecount++;
        }

        if(onecount != 1) return false;

        int posi = -1;

        for(int i = 0 ; i < 32 ; i++){
            if((n & (1 << i)) != 0 ){
                posi = i + 1;
                break;
            }
        }

        if(posi%2 == 0 ) return false;
        return true;
    }
};