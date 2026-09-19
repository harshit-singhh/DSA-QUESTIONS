class Solution {
public:

    #define MOD 1000000007

    void fill_prev_smaller(vector<int>&prevSmaller , vector<int>&arr , int n){
        stack<int>st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                prevSmaller[i] = st.top();
                st.push(i);
            }
            else if(st.empty()){
                prevSmaller[i] = -1;
                st.push(i);
            }
        }
    }
    void fill_next_smaller(vector<int>&nextSmaller , vector<int>&arr , int n){
        stack<int>st;

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                nextSmaller[i] = st.top();
                st.push(i);
            }
            else if(st.empty()){
                nextSmaller[i] = n;
                st.push(i);
            }
        }

        
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int>prevSmaller(n , -1);
        vector<int>nextSmaller(n , n);

        fill_prev_smaller(prevSmaller , arr , n);
        fill_next_smaller(nextSmaller , arr , n);

        long long total = 0;

        for(int i = 0 ; i < n ; i++ ){
            long long m = i - prevSmaller[i];
            long long n = nextSmaller[i] - i;

            long long subarrays = (m*n)%MOD;
            long long subarrays_sum = (subarrays* arr[i])%MOD;

            total = (total + subarrays_sum ) % MOD;
        }

        return total;

    }
};