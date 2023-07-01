class Solution {
public:

     vector<int> findNextLarger(vector<int>arr,int n ){
        vector<int>final(n);
        stack<int>st;
        
        for(int i = n-1; i >= 0 ; i --){
            while(!st.empty() && arr[i] > arr[st.top()]){
                st.pop();
            }
            
            if(!st.empty()){
                final[i] = st.top();
                st.push(i);
            }
            else{
                final[i] = n;
                st.push(i);
            }
        }
        
        return final;
        
        
    }
    
    vector<int> findPrevLarger(vector<int> arr, int n){
        vector<int>final(n);
        stack<int>st;
        
        for(int i = 0; i < n ; i ++){
            while(!st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }
            
            if(!st.empty()){
                final[i] = st.top();
                st.push(i);
            }
            else{
                final[i] = -1;
                st.push(i);
            }
        }
        
        return final;
    }
    
    vector<int>findNextSmaller(vector<int>arr , int n){
        vector<int>final(n);
        stack<int>st;
        
        for(int i = n-1; i >= 0 ; i --){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }
            
            if(!st.empty()){
                final[i] = st.top();
                st.push(i);
            }
            else{
                final[i] = n;
                st.push(i);
            }
        }
        
        return final;
    }
    
    vector<int>findPrevSmaller(vector<int>arr, int n){
        vector<int>final(n);
        stack<int>st;
        
        for(int i = 0; i < n ; i ++){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            
            if(!st.empty()){
                final[i] = st.top();
                st.push(i);
            }
            else{
                final[i] = -1;
                st.push(i);
            }
        }
        
        return final;

    }
    long long subArrayRanges(vector<int>& arr) {

        int n = arr.size();

        vector<int>nextLarger = findNextLarger(arr,n);
        vector<int>prevLarger = findPrevLarger(arr,n);
        vector<int>nextSmaller = findNextSmaller(arr,n);
        vector<int>prevSmaller = findPrevSmaller(arr,n);
        
        
        long long sum = 0;
        
        for(int i = 0 ; i < n ; i ++){
            long long LARGER = (nextLarger[i] - i)*(i - prevLarger[i]);
            long long SMALLER = (nextSmaller[i] - i)*(i - prevSmaller[i]);


            long long to_add = arr[i]*LARGER;
            long long to_sub = arr[i]*SMALLER;
            
            
            sum+= to_add;
            sum-= to_sub;
        }
        
        return sum;
        
        
    }
};