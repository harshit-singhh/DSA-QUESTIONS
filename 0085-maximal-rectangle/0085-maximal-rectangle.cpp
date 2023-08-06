class Solution {
public:
    void findnse(vector<int>heights , vector<int>&nse , int n ){
        stack<int>st;

        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
                st.push(i);
            }
            else if(st.empty()){
                nse[i] = n;
                st.push(i);
            }
        }
    }

    void findpse(vector<int>heights , vector<int>&pse , int n ){
        stack<int>st;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
                st.push(i);
            }
            else{
                pse[i] = -1;
                st.push(i);
            }
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse(n);
        vector<int>pse(n);

        findnse(heights , nse , n);
        findpse(heights , pse , n);

        int maxarea = 0;

        for(int i = 0 ; i < n ; i++){

            int toright = nse[i] - i;
            int toleft = i - pse[i] - 1;

            int totalwidth = toleft + toright;

            maxarea = max(maxarea , totalwidth*heights[i]);
        }

        return maxarea;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        // make histogram vector

        vector<int>histogram(m, 0);

        int maxarea = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< m ; j++){

                if(matrix[i][j] == '1'){
                    histogram[j]+=1;
                }
                else histogram[j] = 0;
            }
            maxarea = max(maxarea , largestRectangleArea(histogram));
        }

        return maxarea;
    }
};