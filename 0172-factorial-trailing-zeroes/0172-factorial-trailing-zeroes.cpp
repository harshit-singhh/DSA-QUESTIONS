class Solution {
public:
    int trailingZeroes(int n) {
        int denom = 5;
        int count = 0;

        while(n/denom > 0){
            count+= n/denom;
            denom*=5;

        }
        return count;
    }
};