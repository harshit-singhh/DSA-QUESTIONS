class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = customers.size();
        vector<int>dummy(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(grumpy[i] == 0) dummy[i] = 0;
            else dummy[i] = customers[i];
        }

        int left = 0;
        int right = 0;

        int leftindex = -1;
        int rightindex = -1;

        int sum = 0 , maxsum = INT_MIN;
        while(right < n){
            sum += dummy[right];
            int len = right-left+1;
            while(len > minutes){
                
                sum-= dummy[left];
                left++;
                len = right-left+1;
            }

            if(len == minutes){
                if(sum > maxsum){

                    maxsum = sum;
                    leftindex = left;
                    rightindex= right;
                }
            }

            right++;
        }

        int satisfied = 0;
        for(int i = 0 ; i < n ; i++){
            if(i >= leftindex && i <= rightindex){
                satisfied += customers[i];
            }

            else if(grumpy[i] == 0){
                satisfied += customers[i];
            }
        }

        return satisfied;


    }
};