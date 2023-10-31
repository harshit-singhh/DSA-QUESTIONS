class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>ans(n );
        ans[0] = arr[0];

        for(int i = 1 ; i < n ; i++){
            int to_make = arr[i];
            int prevNum = arr[i-1];
            int newnum = 0;

            for(int bit = 0 ; bit < 32 ; bit++){
                int toMakeBit = -1;
                int prevNumBit = -1;

                if((to_make & (1 << bit)) != 0) toMakeBit = 1;
                else toMakeBit = 0;
                if((prevNum & (1 << bit)) != 0 ) prevNumBit = 1;
                else prevNumBit = 0;

                if(toMakeBit == 0 && prevNumBit == 1){
                    newnum = newnum | (1 << bit);
                }
                else if(toMakeBit == 1 && prevNumBit == 0){
                    newnum = newnum | (1 << bit);
                }

            }
            ans[i] = newnum;

        }

        return ans;
    }
};