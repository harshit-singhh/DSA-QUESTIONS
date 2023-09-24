class Solution {
    vector<long long>findleft(vector<int>arr , int n){
        stack<long long>st;
        
        vector<long long>ans(n);
        for(int i = 0 ; i < n ; i++){
            
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i] = st.top();
                st.push(i);
            }
            else{
                ans[i] = -1;
                st.push(i);
            }
        }
        
        return ans;
    }
    
    vector<long long>findright(vector<int>arr , int n){
        stack<long long>st;
        
        vector<long long>ans(n,0);
        for(int i = n-1 ; i >= 0  ; i--){
            
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i] = st.top();
                st.push(i);
            }
            else{
                ans[i] = n;
                st.push(i);
            }
        }
        
        return ans;
    }
public:
    long long maximumSumOfHeights(vector<int>& mh) {
        
        int n = mh.size();
        
        vector<long long>leftMin = findleft(mh ,n);
        vector<long long>rightMin = findright(mh ,n);

        vector<long long>sumLeft(n , 0);
        vector<long long>sumRight(n , 0);

        for(int i = 0 ; i < n ; i++){
            int leftSmallerIndex = leftMin[i];

            long long to_convert = i - leftSmallerIndex;

            sumLeft[i] = to_convert*mh[i];
            if(leftSmallerIndex >= 0 && leftSmallerIndex < n) sumLeft[i] += sumLeft[leftSmallerIndex];
        }

        for(int i = n-1 ; i >= 0 ; i--){
            int rightSmallerIndex = rightMin[i];

            long long to_convert = rightSmallerIndex - i;

            sumRight[i] = to_convert*mh[i];
            if(rightSmallerIndex >= 0 && rightSmallerIndex < n) sumRight[i] += sumRight[rightSmallerIndex];
        }



        // for(auto it: leftMin) cout<<it<<" ";
        // cout<<endl;
        // for(auto it: rightMin) cout<<it<<" ";
        // cout<<endl;
        // for(auto it: sumLeft) cout<<it<<" ";
        // cout<<endl;
        // for(auto it: sumRight) cout<<it<<" ";
        // cout<<endl;


        long long maxi = LLONG_MIN;

        for(int i = 0 ; i < n ; i++){
            
            long long val = sumLeft[i] + sumRight[i] - mh[i];

            maxi = max(maxi , val);
            


        }
        return maxi;

    }
};