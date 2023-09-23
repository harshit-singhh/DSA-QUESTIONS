class Solution {
public:
    int reachNumber(int target) {
        int sum = 0;
        int count = 0;
        int curr = 1;
        int D = abs(target);
        while(true){
            
            sum += curr;
            curr++;
            count++;
            if(sum == D){
                return count;
            }
            if(sum > D && (sum - D)%2 == 0 ){
                return count;
                break;
            }
        }
        
        return 0;
    }
};