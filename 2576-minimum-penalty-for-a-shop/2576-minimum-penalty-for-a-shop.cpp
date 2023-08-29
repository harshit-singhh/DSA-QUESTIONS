class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int>preY(n+1);
        preY[n] = 0;
        vector<int>preN(n+1);


        int count = 0;
        for(int i = n-1 ; i>= 0 ; i--){
            if(customers[i] == 'Y') count++;
            preY[i] = count;
        }
        count = 0;
        for(int i = 0 ; i < n ; i++){
            preN[i] = count;
            if(customers[i] == 'N') count++;
        }
        preN[n] = preN[n-1];

        int min = INT_MAX;
        int minindex = INT_MAX;
        for(int i = 0 ; i <= n ; i++){
            
            int loss = preY[i] + preN[i];
            


            if(loss < min){
                min = loss;
                minindex = i;
            }
        }

       

        return minindex;
    }
};