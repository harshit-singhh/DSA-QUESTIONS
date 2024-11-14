class Solution {
public:

    vector<int>findNextSmaller(vector<int>arr , int n){

        stack<int>st;
        vector<int>ans(n , 0);

        for(int i = n-1 ; i >= 0  ; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = n;
                st.push(i);
            }
            else{
                ans[i] = st.top();
                st.push(i); 
            }
        }

        return ans;

    }

    vector<int>findPrevSmaller(vector<int>arr , int n){
        stack<int>st;
        vector<int>ans(n , 0);

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
                st.push(i);
            }
            else{
                ans[i] = st.top();
                st.push(i); 
            }
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();


    

        vector<int>nextSmaller = findNextSmaller(arr,  n );
        vector<int>prevSmaller = findPrevSmaller(arr , n);

        for(auto it: nextSmaller){
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it : prevSmaller){
            cout<<it<<" ";
        }
        cout<<endl;

        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i ++){

            int len = arr[i];
            int wid = (nextSmaller[i] - prevSmaller[i]) -1;
            int area = len*wid;
            maxi = max(maxi , area);
        }
        return maxi;
    }
};