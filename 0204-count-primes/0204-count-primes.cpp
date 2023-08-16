class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool>arr(n , true);

        if(n <= 2) return 0;


        arr[0] = false;
        arr[1] = false;

        int count = 0;

        for(int i = 2 ; i < n ; i++){

            if(arr[i] != false){
                count++;

                for(int k = 2*i ; k < n ; k += i){
                    if(k%i == 0){
                        arr[k] = false;
                    }
                }
            }
        }
        return count;
    }
};