class Solution {
    private:
    void findnsl(vector<int>&arr, vector<int>&nsl , int n){
        stack<int>st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nsl[i] = st.top();
                st.push(i);
            }
            else if(st.empty()){
                nsl[i] = -1;
                st.push(i);
            }
        }
    }

    void findnsr(vector<int>&arr , vector<int>&nsr , int n){
        stack<int>st;

        for(int i = n-1 ; i >=0 ; i--){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nsr[i] = st.top();
                st.push(i);
            }
            else if(st.empty()){
                nsr[i] = n;
                st.push(i);
            }
        }
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
         
         int n = arr.size();
         vector<int>nsl(n);

         vector<int>nsr(n);
         int mod = 1e9+7;

         findnsl(arr,nsl , n );
         findnsr(arr ,nsr , n);

        int totalsum = 0;
         for(int i = 0 ; i< n ; i++){
             int leftsize = i - nsl[i];
             int rightsize = nsr[i] - i;

            long long totalways = leftsize*rightsize;
            long long sum = totalways*arr[i];
             totalsum = (totalsum + sum)%mod;
         }
         return totalsum;
    }
};